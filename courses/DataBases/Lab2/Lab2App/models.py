import datetime

import MySQLdb as mdb
import json

class Database:

    config_json = "Lab2App/static/Lab2App/Files/config.json"
    directors_xml = "Lab2App/static/Lab2App/Files/Directors.xml"
    films_xml = "Lab2App/static/Lab2App/Files/Films.xml"
    studios_xml = "Lab2App/static/Lab2App/Files/Studios.xml"

    con = None
    files = False

    def __init__(self):
        with open(Database.config_json, 'r') as f:
            data = json.load(f)
        self.con = mdb.connect(data['host'], data['user'], data['password'],
                               data['database'], port=data['port'])
        self.load_files()
        print("Open!")

    def load_files(self):
        if not self.files and self.dimension_rows_count() is not 3:

            cur = self.con.cursor()

            cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Directors ROWS IDENTIFIED BY '<Director>';",
                        (self.directors_xml,))

            cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Films ROWS IDENTIFIED BY '<Film>';",
                        (self.films_xml,))

            cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Studios ROWS IDENTIFIED BY '<Studio>';",
                        (self.studios_xml,))

            cur.close()

            self.con.commit()

            self.files = True

    def truncate_dimensions_table(self):

        cur = self.con.cursor()

        cur.execute('SET FOREIGN_KEY_CHECKS = 0;')
        cur.execute('TRUNCATE Films;')
        cur.execute('TRUNCATE Directors;')
        cur.execute('TRUNCATE Studios;')
        cur.execute('SET FOREIGN_KEY_CHECKS = 1;')

        cur.close()
        self.con.commit()

    def dimension_rows_count(self):
        cur = self.con.cursor()

        cur.execute('SELECT * FROM Films;')

        count = cur.rowcount

        cur.close()
        self.con.commit()

        return count

    def get_dicts_of_dimensions(self, table_name):

        cur = self.con.cursor()

        if table_name is "Directors" or table_name is "Films"\
            or table_name is "Studios":
            sql = "SELECT * FROM %s ;" % (table_name)
            cur.execute(sql)
        else:
            cur.close()
            return dict()

        data = []

        for i in range(cur.rowcount):
            data.append(cur.fetchone())

        cur.close()
        self.con.commit()
        return self.make_list_of_dicts_dimensions(table_name, data)

    def make_list_of_dicts_dimensions(self, table_name, list_of_tuple):
        dicts = []
        if table_name is "Directors":
            fields = ['id', 'name', 'country', 'oscar', 'bio']
        elif table_name is "Films":
            fields = ['id', 'name', 'duration', 'budget']
        elif table_name is "Studios":
            fields = ['id', 'name', 'country', 'year', 'history']
        else:return []

        for tuple in list_of_tuple:
            dicts.append(dict(zip(fields, tuple)))
        return dicts

    def add_fact(self, fact):

        cur = self.con.cursor()

        fact['date'] = str(datetime.date.today())

        cur.execute("INSERT INTO Film_creations(Film_id, Director_id, Studio_id, Date) "
                    "VALUES(%s, %s, %s, %s);", (fact['filmId'], fact['directorId'],
                                               fact['studioId'], fact['date']))

        cur.execute('SELECT * FROM Film_creations ORDER BY Id DESC LIMIT 0,1;')

        newFact = cur.fetchone()
        self.con.commit()
        cur.close()

        return self.fact_to_dict(newFact)

    def fact_to_dict(self, fact):
        fields = ['id', 'film', 'director', 'studio', 'date']

        factDict = dict(zip(fields, fact))

        factDict['film'] = self.get_field_from_table_by_id('Films', factDict['film'], 'Name')
        factDict['director'] = self.get_field_from_table_by_id('Directors', factDict['director'], 'Name')
        factDict['studio'] = self.get_field_from_table_by_id('Studios', factDict['studio'], 'Name')
        factDict['date'] = str(factDict['date'])

        return factDict

    def get_dicts_of_facts(self):

        cur = self.con.cursor()

        cur.execute("SELECT * FROM Film_creations;")

        data = []

        for i in range(cur.rowcount):
            data.append(self.fact_to_dict(cur.fetchone()))

        cur.close()

        return data

    def get_field_from_table_by_id(self, table, id, field):

        cur = self.con.cursor()

        sql = "SELECT %s FROM %s WHERE Id = %d ;" % (field, table, id)
        cur.execute(sql)

        data = cur.fetchone()

        cur.close()
        return data[0]

    def get_all_id_and_name(self, table_name):
        cur = self.con.cursor()

        if table_name is "Directors" or table_name is "Films" \
                or table_name is "Studios":
            sql = "SELECT Id, Name FROM %s" % (table_name)
            cur.execute(sql)
        else:
            cur.close()
            return dict()

        data = []

        for i in range(cur.rowcount):
            data.append(cur.fetchone())

        cur.close()
        self.con.commit()

        return self.make_list_of_dicts_dimensions(table_name, data)

    def delete_fact(self, id):

        cur = self.con.cursor()

        sql = "DELETE FROM Film_creations WHERE Id = %s;" % id

        cur.execute(sql)
        self.con.commit()
        cur.close()

    def edit_fact(self, id, fact):

        cur = self.con.cursor()

        sql = "UPDATE Film_creations SET Film_id = %s, Director_id = %s, " \
              "Studio_id = %s WHERE Id = %s;" % (fact['filmId'], fact['directorId'],
                                               fact['studioId'], id)

        sqlGet = "SELECT * FROM Film_creations WHERE Id = %s;" % id
        cur.execute(sql)
        cur.execute(sqlGet)
        data = cur.fetchone()
        self.con.commit()
        cur.close()

        return self.fact_to_dict(data)

    def truncate_facts(self):

        cur = self.con.cursor()

        sql = "TRUNCATE Film_creations;"

        cur.execute(sql)
        self.con.commit()
        cur.close()

    def close_connection(self):
        self.con.close()
        print("Close!")
