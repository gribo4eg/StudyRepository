# -*- coding: utf-8 -*-
# Generated by Django 1.11.6 on 2017-12-05 21:58
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Directors',
            fields=[
                ('id', models.AutoField(db_column='Id', primary_key=True, serialize=False)),
                ('name', models.CharField(blank=True, db_column='Name', max_length=45, null=True)),
                ('country', models.CharField(blank=True, db_column='Country', max_length=45, null=True)),
                ('oscar', models.IntegerField(blank=True, db_column='Oscar', null=True)),
                ('bio', models.TextField(blank=True, db_column='Bio', null=True)),
            ],
            options={
                'db_table': 'Directors',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='FilmCreations',
            fields=[
                ('id', models.AutoField(db_column='Id', primary_key=True, serialize=False)),
                ('date', models.DateField(blank=True, db_column='Date', null=True)),
            ],
            options={
                'db_table': 'Film_creations',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Films',
            fields=[
                ('id', models.AutoField(db_column='Id', primary_key=True, serialize=False)),
                ('name', models.CharField(blank=True, db_column='Name', max_length=45, null=True)),
                ('duration', models.IntegerField(blank=True, db_column='Duration', null=True)),
                ('budget', models.IntegerField(blank=True, db_column='Budget', null=True)),
            ],
            options={
                'db_table': 'Films',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Studios',
            fields=[
                ('id', models.AutoField(db_column='Id', primary_key=True, serialize=False)),
                ('name', models.CharField(blank=True, db_column='Name', max_length=45, null=True)),
                ('year', models.IntegerField(blank=True, db_column='Year', null=True)),
                ('country', models.CharField(blank=True, db_column='Country', max_length=45, null=True)),
                ('history', models.TextField(blank=True, db_column='History', null=True)),
            ],
            options={
                'db_table': 'Studios',
                'managed': False,
            },
        ),
    ]
