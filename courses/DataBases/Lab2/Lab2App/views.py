import MySQLdb

from django.core.serializers import json
from django.http import HttpResponse
from django.shortcuts import render
from django.views import generic

from .models import Database

class IndexView(generic.ListView):
    template_name = 'Lab2App/index.html'

    def get_queryset(self):
        pass

def keke(request):

    return HttpResponse()
