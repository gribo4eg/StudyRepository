import datetime
import ast
from django.http import JsonResponse
from django.views import generic
from .models import *
from django.apps import apps


class IndexView(generic.ListView):
    template_name = 'Lab3App/index.html'

    def get_queryset(self):
        pass

class HistoryView(generic.ListView):
    template_name = 'Lab3App/history.html'
    context_object_name = 'history_list'

    def get_queryset(self):
        return History.objects.order_by('-date')

def all_facts(request):

    if request.method == 'GET':
        return get_all_facts(request)
    elif request.method == 'POST':
        return post_fact(request)
    elif request.method == 'DELETE':
        return delete_facts(request)

def get_all_facts(request):
    facts_q = get_facts()

    res = dict({
        'facts': list(facts_q)
    })
    return JsonResponse(res)

def post_fact(request):
    dataStr = request.body.decode('utf-8')
    fact = ast.literal_eval(dataStr)
    newFact = FilmCreations.objects.create(film_id = fact['filmId'], director_id = fact['directorId'],
                            studio_id = fact['studioId'], date = str(datetime.date.today()))

    newFact = get_facts(newFact.id)

    res = dict({
        'fact': list(newFact)[0]
    })
    return JsonResponse(res)

def delete_facts(request):
    FilmCreations.objects.all().delete()
    res = dict({'status':True})
    return JsonResponse(res)

def fact(request, id):
    if request.method == 'PUT':
        return put_fact(request, id)
    elif request.method == 'DELETE':
        return delete_fact(request, id)

def put_fact(request, id):
    dataStr = request.body.decode('utf-8')
    fact = ast.literal_eval(dataStr)

    FilmCreations.objects.filter(id=int(id)).update(film_id = fact['filmId'],
                                director_id = fact['directorId'], studio_id = fact['studioId'])

    newFact = get_facts(id)
    res = dict({'fact': list(newFact)[0]})
    return JsonResponse(res)

def delete_fact(request, id):
    FilmCreations.objects.filter(id=int(id)).delete()
    res = dict({'status':'OK'})
    return JsonResponse(res)



def bool_search(request):
    if request.method == 'GET':
        oscar = request.GET.get('oscar')

        directors = Directors.objects.filter(oscar=oscar).values()

        res = dict({'directors':list(directors)})
        return JsonResponse(res)

def range_search(request):
    if request.method == 'GET':
        bottom = request.GET.get('bottom')
        top = request.GET.get('top')

        films = Films.objects.filter(budget__range=[bottom,top]).values()

        res = dict({'films':list(films)})
        return JsonResponse(res)

def get_dim_names_ids(request):

    directors = get_all_id_name_dim("Directors")
    films = get_all_id_name_dim("Films")
    studios = get_all_id_name_dim("Studios")

    res = dict({
        'data': {
            'directors': directors,
            'films': films,
            'studios': studios
        }
    })

    return JsonResponse(res)

def get_all_id_name_dim(dim_name):
    Dimension = apps.get_model('Lab3App', dim_name)
    return list(Dimension.objects.values('id','name'))

def get_facts(id=None):
    if id is None:
        return FilmCreations.objects\
            .values('id', 'film__name', 'director__name', 'studio__name', 'date').order_by('id')
    else:
        return FilmCreations.objects.filter(id=int(id)).values('id', 'film__name','director__name', 'studio__name', 'date')