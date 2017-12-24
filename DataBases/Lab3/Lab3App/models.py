# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey has `on_delete` set to the desired behavior.
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
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
    director = models.ForeignKey(Directors, models.DO_NOTHING, db_column='Director_id', blank=True, null=True)  # Field name made lowercase.
    studio = models.ForeignKey('Studios', models.DO_NOTHING, db_column='Studio_id', blank=True, null=True)  # Field name made lowercase.
    date = models.DateField(db_column='Date', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'Film_creations'


class Films(models.Model):
    id = models.AutoField(db_column='Id', primary_key=True)  # Field name made lowercase.
    name = models.CharField(db_column='Name', max_length=45, blank=True, null=True)  # Field name made lowercase.
    duration = models.IntegerField(db_column='Duration', blank=True, null=True)  # Field name made lowercase.
    budget = models.IntegerField(db_column='Budget', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'Films'


class History(models.Model):
    id = models.AutoField(db_column='Id', primary_key=True)  # Field name made lowercase.
    filmCreations_id = models.IntegerField(db_column='FilmCreations_Id')  # Field name made lowercase.
    filmHistory = models.CharField(db_column='FilmHistory', max_length=80, blank=True, null=True)  # Field name made lowercase.
    directorHistory = models.CharField(db_column='DirectorHistory', max_length=80, blank=True, null=True)  # Field name made lowercase.
    studioHistory = models.CharField(db_column='StudioHistory', max_length=80, blank=True, null=True)  # Field name made lowercase.
    date = models.DateTimeField(db_column='Date')  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'History'


class Studios(models.Model):
    id = models.AutoField(db_column='Id', primary_key=True)  # Field name made lowercase.
    name = models.CharField(db_column='Name', max_length=45, blank=True, null=True)  # Field name made lowercase.
    year = models.IntegerField(db_column='Year', blank=True, null=True)  # Field name made lowercase.
    country = models.CharField(db_column='Country', max_length=45, blank=True, null=True)  # Field name made lowercase.
    history = models.TextField(db_column='History', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'Studios'

##[jetbrains/home/alexander/Documents/Repository/StudyRepository/DataBases/Lab3/Lab3App/models.py
