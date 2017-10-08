from django.db import models

class Soundtrack(models.Model):
    name = models.CharField(max_length=50)
    musician = models.CharField(max_length=50)
    album = models.CharField(max_length=50)
    year = models.PositiveSmallIntegerField()

    def __str__(self):
        return "'%s' %s" % (self.name, self.musician)

class Director(models.Model):
    name = models.CharField(max_length=50)
    country = models.CharField(max_length=50)
    birth_date = models.DateTimeField()

    def __str__(self):
        return self.name

class Studio(models.Model):
    name = models.CharField(max_length=50)
    country = models.CharField(max_length=50)
    year = models.PositiveSmallIntegerField()

    def __str__(self):
        return self.name

class Film(models.Model):
    soundtrack = models.ForeignKey(Soundtrack, on_delete=models.SET_NULL)
    director = models.ForeignKey(Director, on_delete=models.SET_NULL)
    studio = models.ForeignKey(Studio, on_delete=models.SET_NULL)
    name = models.CharField(max_length=50)
    budget = models.PositiveIntegerField()
    duration = models.PositiveSmallIntegerField()
    date = models.DateTimeField()

    def __str__(self):
        return self.name