from __future__ import unicode_literals

from django.db import models


class Directors(models.Model):
    id = models.AutoField(db_column='Id', primary_key=True)
    name = models.CharField(db_column='Name', max_length=45, blank=True, null=True)
    country = models.CharField(db_column='Country', max_length=45, blank=True, null=True)
    oscar = models.IntegerField(db_column='Oscar', blank=True, null=True)
    bio = models.TextField(db_column='Bio', blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Directors'


class FilmCreations(models.Model):
    id = models.AutoField(db_column='Id', primary_key=True)
    film = models.ForeignKey('Films', models.DO_NOTHING, db_column='Film_id', blank=True, null=True)
    director = models.ForeignKey(Directors, models.DO_NOTHING, db_column='Director_id', blank=True, null=True)
    studio = models.ForeignKey('Studios', models.DO_NOTHING, db_column='Studio_id', blank=True, null=True)
    date = models.DateField(db_column='Date', blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Film_creations'


class Films(models.Model):
    id = models.AutoField(db_column='Id', primary_key=True)
    name = models.CharField(db_column='Name', max_length=45, blank=True, null=True)
    duration = models.IntegerField(db_column='Duration', blank=True, null=True)
    budget = models.IntegerField(db_column='Budget', blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Films'


class History(models.Model):
    id = models.AutoField(db_column='Id', primary_key=True)
    filmCreations_id = models.IntegerField(db_column='FilmCreations_Id')
    filmHistory = models.CharField(db_column='FilmHistory', max_length=80, blank=True, null=True)
    directorHistory = models.CharField(db_column='DirectorHistory', max_length=80, blank=True, null=True)
    studioHistory = models.CharField(db_column='StudioHistory', max_length=80, blank=True, null=True)
    date = models.DateTimeField(db_column='Date')

    class Meta:
        managed = False
        db_table = 'History'


class Studios(models.Model):
    id = models.AutoField(db_column='Id', primary_key=True)
    name = models.CharField(db_column='Name', max_length=45, blank=True, null=True)
    year = models.IntegerField(db_column='Year', blank=True, null=True)
    country = models.CharField(db_column='Country', max_length=45, blank=True, null=True)
    history = models.TextField(db_column='History', blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Studios'

