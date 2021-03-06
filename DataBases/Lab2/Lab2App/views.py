import json
import ast

from django.http import HttpResponse
from django.views import generic

from .models import Database

class IndexView(generic.ListView):
    template_name = 'Lab2App/index.html'

    def get_queryset(self):
        pass

def load_files(request):
    db = Database()
    db.load_files()
    db.close_connection()


    res = get_dim_names_ids()
    return HttpResponse(json.dumps(res), content_type='application/json')


def all_facts(request):

    if request.method == 'GET':
        return get_all_facts(request)
    elif request.method == 'POST':
        return post_fact(request)
    elif request.method == 'DELETE':
        return truncate_facts(request)

def get_all_facts(request):
    db = Database()

    facts = db.get_dicts_of_facts()

    db.close_connection()

    res = dict({
        'facts': facts
    })

    return HttpResponse(json.dumps(res), content_type='application/json')

def post_fact(request):

    dataStr = request.body.decode('utf-8')
    fact = ast.literal_eval(dataStr)
    db = Database()
    newFact = db.add_fact(fact)
    db.close_connection()
    return HttpResponse(json.dumps(newFact), content_type='application/json')

def truncate_facts(request):
    db = Database()
    db.truncate_facts()
    db.close_connection()
    res = dict({'status':True})
    return HttpResponse(json.dumps(res), content_type='application/json')

def fact(request, id):
    if request.method == 'GET':
        return get_fact(request, id)
    elif request.method == 'PUT':
        return put_fact(request, id)
    elif request.method == 'DELETE':
        return delete_fact(request, id)

def get_fact(request, id):
    pass

def put_fact(request, id):
    dataStr = request.body.decode('utf-8')
    fact = ast.literal_eval(dataStr)
    db = Database()

    newFact = db.edit_fact(id, fact)

    db.close_connection()

    res = dict({'fact': newFact})
    return HttpResponse(json.dumps(res), content_type='application/json')

def delete_fact(request, id):
    db = Database()

    db.delete_fact(id)

    db.close_connection()

    res = dict({'status':'OK'})
    return HttpResponse(json.dumps(res), content_type='application/json')

def get_dimensions_names_and_id(request):

    if request.method == 'GET':

        res = get_dim_names_ids()

        return HttpResponse(json.dumps(res), content_type='application/json')

def bool_search(request):
    if request.method == 'GET':
        oscar = request.GET.get('oscar')

        db = Database()
        directors = db.search_directors_oscar(oscar)
        db.close_connection()

        res = dict({'directors':directors})
        return HttpResponse(json.dumps(res), content_type='application/json')

def range_search(request):
    if request.method == 'GET':
        bottom = request.GET.get('bottom')
        top = request.GET.get('top')

        db = Database()
        films = db.search_films_range(bottom, top)
        db.close_connection()

        res = dict({'films':films})
        return HttpResponse(json.dumps(res), content_type='application/json')

def word_text_search(request):
    if request.method == 'GET':
        searchType = request.GET.get('type')
        search = request.GET.get('search')
        if searchType == 'word':
            search = '+' + search.replace(' ','+')
        else:
            search = ''.join(('"',search,'"'))
        db = Database()
        studios = db.search_studios_word_text(search)
        db.close_connection()
        res = dict({'studios':studios})
        return HttpResponse(json.dumps(res), content_type='application/json')

def get_dim_names_ids():
    db = Database()
    directors = db.get_all_id_and_name("Directors")
    films = db.get_all_id_and_name("Films")
    studios = db.get_all_id_and_name("Studios")
    db.close_connection()

    return dict({
        'data': {
            'directors': directors,
            'films': films,
            'studios': studios
        }
    })

