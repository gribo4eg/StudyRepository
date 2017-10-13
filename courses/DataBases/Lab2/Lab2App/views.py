import MySQLdb
import json

from django.http import HttpResponse
from django.shortcuts import render
from django.views import generic

from .models import Database

class IndexView(generic.ListView):
    template_name = 'Lab2App/index.html'

    def get_queryset(self):
        pass

def get_all_dimensions(request):

    db = Database()

    directors = db.get_directors_dicts()
    films = db.get_films_dicts()
    studios = db.get_studios_dicts()

    db.close_connection()

    res = dict({
        'data':{
            'directors':directors,
            'films':films,
            'studios':studios
        }
    })

    print("Sending data!")
    return HttpResponse(json.dumps(res), content_type='application/json')
