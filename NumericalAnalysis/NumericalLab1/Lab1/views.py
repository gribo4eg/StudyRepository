from django.http import HttpResponse
from django.views import generic

from .models import *

import ast, json

class IndexView(generic.ListView):
    template_name = 'Lab1/index.html'

    def get_queryset(self):
        pass


def invoke_functions_calc(request):
    data = ast.literal_eval(request.body.decode('utf-8'))
    method = define_method(data['method'])
    epsilon = float(data['epsilon'])
    func = data['function']
    interval = list()
    for i in data['interval']:
        interval.append(float(i))
    try:
        answer = method(interval[0], interval[1], epsilon)
    except Exception as e:
        res = dict({'err':e.args})
    else:
        res = form_response_f(answer, func, interval)
    return HttpResponse(json.dumps(res), content_type='application_json')


def form_response_f(method_answer, func, interval):
    rootPlot = PlotBuilder.build(func, interval[0], interval[1])
    taskX = list()
    taskY = list()
    for i in range(len(method_answer[0])):
        taskX.append(i+1)
        taskY.append(method_answer[0][i][1])
    return dict({
        'answer': {
            'steps': method_answer[0],
            'x': method_answer[1],
        },
        'rootPlot': {
            'name':'Plot for root',
            'x':rootPlot[0],
            'y':rootPlot[1]
        },
        'taskPlot': {
            'name':'Task plot',
            'x':taskX,
            'y':taskY
        }
    })


def define_method(method):
    if method == 'bisection':
        return Methods.bisection_method
    elif method == 'hybrid':
        return Methods.hybrid_method
    elif method == 'iteration':
        return Methods.fixed_point_iteration_method


def invoke_lobachevsky_method(request):
    data = ast.literal_eval(request.body.decode('utf-8'))
    numbers = list()
    epsilon = float(data['epsilon'])
    n = int(data['n'])
    c = len(data['values'])
    for i in range(0, n+1, 1):
        numbers.append(int(data['values'][i]))
    print(numbers)
    print(epsilon)
    print(n)
    print(c)
    try:
        answer = Lobachevsky.calculate(numbers, epsilon, n)
    except Exception as e:
        res = dict({ 'err' : e.args })
    else:
        res = form_response_l(answer, numbers, epsilon, n, c)
    return HttpResponse(json.dumps(res), content_type='application/json')


def form_response_l(answer, numbers, epsilon, n, c):
    rootsN = Methods.newtons_method(answer[1], epsilon, n, numbers)
    positive, negative = Root_Analysis.get_analysis(numbers)
    return dict({
        'steps': form_steps(answer[0], c),
        'roots': {
            'rootsL': form_roots(answer[1], c),
            'rootsN': form_roots(rootsN, c)
        },
        'analysis': {
            'positive': positive,
            'negative': negative
        }
    })


def form_roots(roots, n):
    while len(roots) < n-1:
        roots.append('-')
    return roots


def form_steps(steps, n):
    res = list()
    for i in steps:
        while len(i[1]) < n:
            i[1].append('-')
        res.append(dict({
            'p':i[0],
            'n':i[2],
            'numbers':i[1]
        }))
    return res