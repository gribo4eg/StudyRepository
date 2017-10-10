from django.conf.urls import url, include

from . import views

app_name = 'Lab2App'
urlpatterns = [
    url(r'^$', views.IndexView.as_view(), name='index'),
    url(r'^kek/$', views.keke),
]