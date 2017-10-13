import MySQLdb as mdb
import json

class Database():

    config_json = "Lab2App/static/Lab2App/config.json"
    directors_xml = "Lab2App/static/Lab2App/Directors.xml"
    films_xml = "Lab2App/static/Lab2App/Films.xml"
    studios_xml = "Lab2App/static/Lab2App/Studios.xml"

    con = None

    def __init__(self):
        if not self.con:
            with open(self.config_json, 'r') as f:
                data = json.load(f)
            self.con = mdb.connect(data['host'], data['user'],
                                       data['password'], data['database'])
            if self.con:
                print("Connected to %s with %s user!" % (data['database'], data['user']))
            else: print("No connection!")

    def get_directors_dicts(self):
        cur = self.con.cursor()

        cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Directors ROWS IDENTIFIED BY '<Director>';",
                    (self.directors_xml,))

        cur.execute("SELECT * FROM Directors;")

        data = []

        for i in range(cur.rowcount):
            data.append(cur.fetchone())

        directors = self.make_list_of_dicts("Directors", data)

        return directors

    def get_films_dicts(self):
        cur = self.con.cursor()

        cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Films ROWS IDENTIFIED BY '<Film>';",
                    (self.films_xml,))

        cur.execute("SELECT * FROM Films;")

        data = []

        for i in range(cur.rowcount):
            data.append(cur.fetchone())

        films = self.make_list_of_dicts("Films", data)

        return films

    def get_studios_dicts(self):
        cur = self.con.cursor()

        cur.execute("LOAD XML LOCAL INFILE %s INTO TABLE Studios ROWS IDENTIFIED BY '<Studio>';",
                    (self.studios_xml,))

        cur.execute("SELECT * FROM Studios;")

        data = []

        for i in range(cur.rowcount):
            data.append(cur.fetchone())

        studios = self.make_list_of_dicts("Studios", data)

        return studios

    def make_list_of_dicts(self, table_name, list_of_tuple):
        dicts = []
        if table_name == "Directors":
            fields = ['director_id', 'name', 'country', 'oscar', 'bio']
        elif table_name == "Films":
            fields = ['film_id', 'name', 'duration', 'budget']
        elif table_name == "Studios":
            fields = ['studio_id', 'name', 'country', 'year', 'history']
        else:return []

        for tuple in list_of_tuple:
            dicts.append(dict(zip(fields, tuple)))
        return dicts


    def close_connection(self):
        if self.con:
            self.con.close()
            print("Disconnect from MySQL db")
            self.con = None
