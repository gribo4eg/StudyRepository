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
        print("Open!")

    def xml_to_db(self):
        cur = self.con.cursor()
        cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Directors ROWS IDENTIFIED BY '<Director>';",
                    (self.directors_xml,))
        cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Films ROWS IDENTIFIED BY '<Film>';",
                    (self.films_xml,))
        cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Studios ROWS IDENTIFIED BY '<Studio>';",
                    (self.studios_xml,))
        cur.close()
        self.con.commit()

    def load_files(self):
        self.truncate_dimensions_table()
        self.xml_to_db()

    def truncate_dimensions_table(self):

        cur = self.con.cursor()

        cur.execute('SET FOREIGN_KEY_CHECKS = 0;')
        cur.execute('TRUNCATE Films;')
        cur.execute('TRUNCATE Directors;')
        cur.execute('TRUNCATE Studios;')
        cur.execute('SET FOREIGN_KEY_CHECKS = 1;')

        cur.close()
        self.con.commit()

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
            fields = ['id', 'name', 'year', 'country', 'history']
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

        sql = "SELECT Film_creations.Id, Films.Name, Directors.Name, Studios.Name, Film_creations.Date " \
              "FROM (((Film_creations " \
              "INNER JOIN Films ON Film_creations.Film_id = Films.Id) " \
              "INNER JOIN Directors ON Film_creations.Director_id = Directors.Id) " \
              "INNER JOIN Studios ON Film_creations.Studio_id = Studios.Id) " \
              "ORDER BY Film_creations.Id DESC LIMIT 0,1;"
        cur.execute(sql)

        newFact = cur.fetchone()
        self.con.commit()
        cur.close()
        return self.fact_to_dict(newFact)

    def fact_to_dict(self, fact):
        fields = ['id', 'film', 'director', 'studio', 'date']

        factDict = dict(zip(fields, fact))

        factDict['date'] = str(factDict['date'])

        return factDict

    def get_dicts_of_facts(self):

        cur = self.con.cursor()

        sql = "SELECT Film_creations.Id, Films.Name, Directors.Name, Studios.Name, Film_creations.Date " \
              "FROM (((Film_creations " \
              "INNER JOIN Films ON Film_creations.Film_id = Films.Id) " \
              "INNER JOIN Directors ON Film_creations.Director_id = Directors.Id) " \
              "INNER JOIN Studios ON Film_creations.Studio_id = Studios.Id);"
        cur.execute(sql)

        data = []

        for i in range(cur.rowcount):
            data.append(self.fact_to_dict(cur.fetchone()))

        cur.close()

        return data

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

        sqlGet = "SELECT Film_creations.Id, Films.Name, Directors.Name, Studios.Name, Film_creations.Date " \
                 "FROM (((Film_creations " \
                 "INNER JOIN Films ON Film_creations.Film_id = Films.Id) " \
                 "INNER JOIN Directors ON Film_creations.Director_id = Directors.Id) " \
                 "INNER JOIN Studios ON Film_creations.Studio_id = Studios.Id) " \
                 "WHERE Film_creations.Id = %s;" % id
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

    def search_directors_oscar(self, oscar):

        cur = self.con.cursor()

        sql = 'SELECT * FROM Directors WHERE Oscar = %s;' % oscar

        cur.execute(sql)

        data = []

        for i in range(cur.rowcount):
            data.append(cur.fetchone())

        cur.close()

        return self.make_list_of_dicts_dimensions('Directors', data)

    def search_films_range(self, bottom, top):

        cur = self.con.cursor()
        sql = 'SELECT * FROM Films WHERE Budget BETWEEN %s AND %s;' % (bottom, top)
        cur.execute(sql)

        data = []
        for i in range(cur.rowcount):
            data.append(cur.fetchone())
        cur.close()
        return self.make_list_of_dicts_dimensions('Films', data)

    def search_studios_word_text(self, word):
        cur = self.con.cursor()
        sql = "SELECT * FROM Studios WHERE MATCH (History) " \
              "against ('%s' in boolean mode);" % word
        cur.execute(sql)
        data = []
        for i in range(cur.rowcount):
            data.append(cur.fetchone())
        cur.close()
        return self.make_list_of_dicts_dimensions('Studios', data)

    def close_connection(self):
        self.con.close()
        print("Close!")
