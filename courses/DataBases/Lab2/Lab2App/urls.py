from django.conf.urls import url, include

from . import views

app_name = 'Lab2App'
urlpatterns = [
    url(r'^$', views.IndexView.as_view(), name='index'),
    url(r'^api/facts/', include([
        url(r'^$', views.all_facts, name='facts'),
        url(r'^(?P<id>[0-9]+)/$', views.fact, name='fact')
    ])),
    url(r'^api/dimensions_names/', views.get_dimensions_names_and_id, name='dimensions_names'),
    url(r'^api/search/', include([
        url(r'^directors/$', views.bool_search, name='bool_search')
    ]))
]

#?oscar=(?P<oscar>[01])