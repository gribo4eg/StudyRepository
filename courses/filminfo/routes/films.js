/**
 * Created by sasha on 12.12.16.
 */
var express = require('express');
var router = express.Router();
var fs = require('fs');

const Film = require('../models/film');
const Actor = require('../models/actor');
const Genre = require('../models/genre');
const User = require('../models/user');


router.get('/', function(req, res) {
    if(req.originalUrl === '/films/' || req.originalUrl === '/films')
        res.redirect('/films?page=1');
    var reqPage = req.query.page;
    var back_url = req.header('Referer') || '/';
    var search = req.query.filmtitle;
    Film.countOfFilms(function (count) {
        var skip = 4 * (reqPage - 1);
        var allpages = count / 4;
        if(count % 4 !== 0)
        {
            allpages++;
        }
        if(reqPage <= 0 || reqPage > allpages)
            res.redirect('/films');
        var pages = {current:reqPage, all:allpages};
        Film.getAllPagination(skip, function (err, doc) {
            console.log("searchreq"+search);
            if(err) res.render('error', {err});
            else res.render('films', {doc, pages, back_url, searchreq:search});
        });
    });
});

router.get('/delete/:_id', function (req, res) {
    console.log(req.originalUrl);
    if(!req.user && !req.user.statusAdmin){
        var err = new Error();
        err.message = "Not found user";
        err.status = 404;
        res.redirect('error', {err});
    } else {
        Film.deleteFilm(req.params._id, function (err, confirm) {
            if(confirm) res.redirect('/films/');
            else res.render('error', {err});
        });
    }
});

/*        ADD FILM       */
router.get('/newfilm', function(req, res){
    if (req.user.statusAdmin) {
        res.render('addfilm', {errors: false});
    } else {
        var error = new Error("Not found user");
        error.status = 404;
        res.render('error',error)
    }
});

router.post('/newfilm', function(req,res){
    if(req.user && !req.user.statusAdmin){
        var err = new Error();
        err.status = 404;
        err.message = "Not found user";
        res.render('error',{err})
    }
    Film.contains(req.body.title.trim(), function (contains) {
        if(contains){
            res.render('addfilm', {errors:[{
                param: "title",
                msg: "Such film is already exists"
            }]});
        }
        else {
            var newFilm = new Film();
            var plot = req.body.plot;
            if(plot || 0 !== plot.size)
                newFilm.plot = plot;

            var genres = req.body.genres;
            var genresTarr = [];
            if(genres && 0!==genres.length) genresTarr = genres.split(';');

            newFilm.title = req.body.title.trim();
            newFilm.director = req.body.director.trim();
            newFilm.budget = req.body.budget;
            newFilm.duration = req.body.duration;
            newFilm.date = req.body.date;
            newFilm.trailer = req.body.link;
            newFilm.poster = req.files.poster[0].data.toString('base64');
            var screensArr = req.files.screens;
            screensArr.forEach(function (item) {
                newFilm.screens.push(item.data.toString('base64'));
            });

            if(genresTarr.length > 0){
                genresTarr.forEach((item, i) => {
                    Genre.addGenre(item, function (genre) {
                        newFilm.genres.push(genre);
                        if(i === genresTarr.length-1){
                            Film.saveFilm(newFilm, function (err, doc) {
                                if(doc) res.redirect('/films/'+doc._id);
                                else res.render('error', err);
                            });
                        }
                    });
                });
            } else {
                Film.saveFilm(newFilm, function (err, doc) {
                    if(doc) res.redirect('/films');
                    else res.render('error', err);
                });
            }
        }
    });
});

/* UPDATE FILM */

router.get('/update/:id', function (req, res) {
    if(req.user && req.user.statusAdmin){
        var id = req.params.id;
        Film.findById(id, function (err, film) {
            Film.getActorsNames(film, function (arr) {
                var actors;
                if(arr && arr.length!==0)
                    actors = arr.join(';');
                else actors = "none";
                res.render('filmupdate', {film, actors});
            });
        });
    } else {
        var err = new Error();
        err.message = "Not found user";
        err.status = 404;
        res.render('error',{err})
    }
});

router.post('/update/:id', function (req, res) {
    var id = req.params.id; var newtitle = req.body.title;
    var newdirector = req.body.director; var newbudget = req.body.budget;
    var newduration = req.body.duration; var newdate = req.body.date;
    var newplot = req.body.plot; var newposter= req.files.poster[0];
    var newlink = req.body.link;
    var newscreen1 = req.files.screen1[0];
    var newscreen2 = req.files.screen2[0];
    var newscreen3 = req.files.screen3[0];
    var newscreen4 = req.files.screen4[0];
    var newscreen5 = req.files.screen5[0];
    var newscreens = []; var actorsTarr = [];

    actorsTarr = req.body.actors.split(';');


    Film.findById(id, function (err, film) {
        film.title = newtitle || film.title;
        film.director = newdirector || film.director;
        film.budget = newbudget || film.budget;
        film.duration = newduration || film.duration;
        film.date = newdate || film.date;
        film.plot = newplot || film.plot;
        film.trailer = newlink || film.trailer;


        if(newposter && 0!==newposter.size) film.poster = newposter.data.toString('base64');

        if(newscreen1 && 0!==newscreen1.size) newscreens.push(newscreen1.data.toString('base64'));
        else newscreens.push(film.screens[0]);
        if(newscreen2 && 0!==newscreen2.size) newscreens.push(newscreen2.data.toString('base64'));
        else newscreens.push(film.screens[1]);
        if(newscreen3 && 0!==newscreen3.size) newscreens.push(newscreen3.data.toString('base64'));
        else newscreens.push(film.screens[2]);
        if(newscreen4 && 0!==newscreen4.size) newscreens.push(newscreen4.data.toString('base64'));
        else newscreens.push(film.screens[3]);
        if(newscreen5 && 0!==newscreen5.size) newscreens.push(newscreen5.data.toString('base64'));
        else newscreens.push(film.screens[4]);


        film.screens = newscreens;


        Film.getActorsNames(film, function (array) {
            var comp = arraysEaquals(actorsTarr, array);
            if(comp && actorsTarr.length !== 0 && actorsTarr[0] !== "none"){
                film.save()
                    .then(doc => {res.redirect("/films/"+doc._id)})
                    .catch(err => res.render('error', {err}));
            } else if(actorsTarr.length > 0 && actorsTarr[0] !== "none"){
                film.actors = [];
                actorsTarr.forEach((item, i) => {
                    Actor.findByName(item, function (err, actor) {
                        if(actor) {
                            if(actor.films.indexOf(film) === -1) {
                                actor.films.push(film);
                                actor.save();
                            }
                            film.actors.push(actor);
                        }
                        if(i === actorsTarr.length - 1){
                            film.save()
                                .then(doc => {res.redirect("/films/"+doc._id)})
                                .catch(err => res.render('error', {err}));
                        }
                    });
                });
            } else {
                film.actors = [];
                film.save()
                    .then(doc => {res.redirect("/films/"+doc._id)})
                    .catch(err => res.render('error', {err}));
            }
        });

    });
});

function arraysEaquals(arr1, arr2) {
    if(arr1.length !== arr2.length) return false;
    arr1.forEach((item, i) => { if(item !== arr2[i] && item.length !== arr2[i].length) return false });
    return true;
}

router.post('/subscribe/:id', function (req, res) {
    if(!req.user){
        var error = new Error("Not found user");
        error.status = 404;
        res.render('error',error);
    } else {
        var id = req.params.id;
        Film.findById(id, function (err, doc) {
            User.subFilm(req.user._id, doc, function (err, status) {
                if(status) res.redirect('/films/'+id);
                else res.render('error',err);
            });
        });
    }
});

router.post('/unsubscribe/:id', function (req, res) {
    if(!req.user){
        var error = new Error("Not found user");
        error.status = 404;
        res.render('error',error)
    } else {
        var id = req.params.id;
        Film.findById(id, function (err, doc) {
            User.unsubFilm(req.user._id, doc, function (err, status) {
                if(status) res.redirect('/films/'+id);
                else res.render('error',err)
            });
        });
    }
});

router.get('/:_id', function (req, res) {
    console.log(req.originalUrl);
    var user = req.user;
    var already = Boolean(false);
    var back_url = req.header('Referer') || '/';
    Film.findById(req.params._id, function (err, doc) {
        if(user){
            user.subfilms.forEach(item => {
                if(String(doc._id) === String(item))
                {already = Boolean(true);}
            });
        }
        if(err) res.render('error', {err});
        else res.render('film', {doc, back_url, user, already});
    });
});



module.exports = router;
