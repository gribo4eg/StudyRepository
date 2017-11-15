from django.conf.urls import url, include

from . import views

app_name = 'Lab1'
urlpatterns = [
    url(r'^$', view=views.IndexView.as_view()),
    url(r'^api/', include([
        url(r'^calc_lobachevsky/$', view=views.invoke_lobachevsky_method),
        url(r'^calc_function/$', view=views.invoke_functions_calc)
    ]))
]