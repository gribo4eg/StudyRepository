/**
 * Created by sasha on 12.12.16.
 */
var express = require('express');
var router = express.Router();

const Actor = require('../models/actor');
const Film = require('../models/film');

/*      ACTORS       */
router.get('/', function(req, res) {
    if(req.originalUrl === '/actors/' || req.originalUrl === '/actors')
        res.redirect('/actors?page=1');
    var reqPage = req.query.page;
    var back_url = req.header('Referer') || '/';
    Actor.countOfActors(function (count) {
        var skip = 4 * (reqPage - 1);
        var allpages = count / 4;
        if(count % 4 !== 0)
        {
            allpages++;
        }
        if(reqPage <= 0 || reqPage > allpages)
            res.redirect('/actors');
        var pages = {current:reqPage, all:allpages};
        Actor.getAllPagination(skip, function (err, doc) {
            if(err) res.render('error', {err});
            else res.render('actors', {doc, pages, back_url});
        });
    });
});

/*        ADD FILM       */
router.get('/newactor', function(req, res){
    if (req.user.statusAdmin) {
        res.render('addactor', {errors: false});
    } else {
        var error = new Error("Not found user");
        error.status = 404;
        res.render('error',error)
    }
});

router.post('/newactor', function(req,res){
    if(req.user && !req.user.statusAdmin){
        var error = new Error("Not found user");
        error.status = 404;
        res.render('error',error)
    }
    Actor.contains(req.body.name.trim(), function (contains) {
        if(contains){
            res.render('addactor', {errors:[{
                param: "name",
                msg: "Such actor is already exists"
            }]});
        }
        else {
            var newActor = new Actor();
            var biography = req.body.biography;
            if(biography || 0 !== biography.length)
                newActor.biography = biography;

            newActor.name = req.body.name.trim();
            newActor.hometown = req.body.hometown.trim();
            newActor.birthdate = req.body.birthdate;
            newActor.photos.push(req.files.photo[0].data.toString('base64'));
            var screensArr = req.files.screens;
            screensArr.forEach(function (item) {
                newActor.photos.push(item.data.toString('base64'));
            });

            Actor.saveActor(newActor, function (err, doc) {
                if(doc) res.redirect('/actors/'+doc._id);
                else res.render('error', err);
            });
        }
    });
});

/* UPDATE FILM */

router.get('/update/:id', function (req, res) {
    if(req.user && req.user.statusAdmin){
        var id = req.params.id;
        Actor.findById(id, function (err, actor) {
            Actor.getFilmsTitles(actor, function (arr) {
                var titles;
                if(arr && arr.length!==0) titles = arr.join(';');
                else titles = "none";
                res.render('actorupdate', {actor, titles});
            })
        });
    } else {
        var err = new Error();
        err.message = "Not found user";
        err.status = 404;
        res.render('error',{err})
    }
});

router.post('/update/:id', function (req, res) {
    var id = req.params.id; var newname = req.body.name;
    var newhometown = req.body.hometown; var newbirthdate = req.body.birthdate;
    var newbiography = req.body.biography;var newphoto= req.files.photo[0];
    var newscreen1 = req.files.screen1[0];
    var newscreen2 = req.files.screen2[0];
    var newscreen3 = req.files.screen3[0];
    var newscreen4 = req.files.screen4[0];
    var newscreen5 = req.files.screen5[0];
    var newscreens = []; var filmsTarr = [];


    filmsTarr = req.body.films.split(';');

    Actor.findById(id, function (err, actor) {
        actor.name = newname || actor.name;
        actor.birthdate = newbirthdate || actor.birthdate;
        actor.hometown = newhometown || actor.hometown;
        actor.biography = newbiography || actor.biography;

        if(newphoto && 0!==newphoto.size) newscreens.push(newphoto.data.toString('base64'));
        else newscreens.push(actor.photos[0]);
        if(newscreen1 && 0!==newscreen1.size) newscreens.push(newscreen1.data.toString('base64'));
        else newscreens.push(actor.photos[1]);
        if(newscreen2 && 0!==newscreen2.size) newscreens.push(newscreen2.data.toString('base64'));
        else newscreens.push(actor.photos[2]);
        if(newscreen3 && 0!==newscreen3.size) newscreens.push(newscreen3.data.toString('base64'));
        else newscreens.push(actor.photos[3]);
        if(newscreen4 && 0!==newscreen4.size) newscreens.push(newscreen4.data.toString('base64'));
        else newscreens.push(actor.photos[4]);
        if(newscreen5 && 0!==newscreen5.size) newscreens.push(newscreen5.data.toString('base64'));
        else newscreens.push(actor.photos[5]);

        actor.photos = newscreens;

        Actor.getFilmsTitles(actor, function (array) {
            var comp = arraysEaquals(filmsTarr, array);
            if(comp && filmsTarr.length !== 0 && filmsTarr[0] !== "none"){
                actor.save()
                    .then(doc => res.redirect('/actors/'+doc._id))
                    .catch(err => res.render('error', {err}));
            } else if(filmsTarr.length > 0 && filmsTarr[0] !== "none"){
                actor.films = [];
                filmsTarr.forEach((item, i) => {
                    Film.findByTitle(item, function (err, film) {
                        if(film) {
                            if(film.actors.indexOf(actor) === -1){
                                film.actors.push(actor);
                                film.save();
                            }
                            actor.films.push(film);
                        }
                        if(i === filmsTarr.length-1){
                            actor.save()
                                .then(doc => res.redirect('/actors/'+doc._id))
                                .catch(err => res.render('error', {err}));
                        }
                    });
                });

            } else {
                actor.films = [];
                actor.save()
                 .then(doc => res.redirect('/actors/'+doc._id))
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


router.post('/delete/:id', function (req, res) {
    if(!req.user && !req.user.statusAdmin){
        var error = new Error("Not found user");
        error.status = 404;
        res.redirect('error', error);
    } else {
        Actor.deleteActor(req.params.id, function (err, confirm) {
            if(confirm) res.redirect('/actors');
            else res.render('error', err);
        });
    }
});

router.get('/:_id', function(req, res){
    var back_url = req.header('Referer') || '/';
    Actor.findById(req.params._id, function (err, doc) {
        if(err) res.render('error', {err});
        else res.render('actor', {doc, back_url});
    });
});

module.exports = router;