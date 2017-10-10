import MySQLdb as mdb
import json

class Soundtrack():
    id = int
    name = str
    musician = str
    album = str
    year = int

    def __str__(self):
        return "'%s' %s" % (self.name, self.musician)

class Director():
    id = int
    name = str
    country = str
    birth_date = str

    def __str__(self):
        return self.name

class Studio():
    id = int
    name = str
    country = str
    year = int

    def __str__(self):
        return self.name

class Film():
    id = int
    soundtrack_id = Soundtrack
    director_id = Director
    studio_id = Studio
    name = str
    budget = int
    duration = int
    date = str

    def __str__(self):
        return self.name

class Database():
    con = None

    @staticmethod
    def connect():
        if not Database.con:
            with open("Lab2App/static/Lab2App/db.json", 'r') as f:
                data = json.load(f)
            Database.con = mdb.connect(data['host'], data['user'],
                                       data['password'], data['database'])
            print('Connection with MySQL db established')

    @staticmethod
    def get_cursor():
        if Database.con:
            return Database.con.cursor()

    @staticmethod
    def close_connection():
        if Database.con:
            Database.con.close()
            print("Disconnect from MySQL db")
            Database.con = None
