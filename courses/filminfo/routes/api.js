/**
 * Created by sasha on 05.12.16.
 */
var express = require('express');
var router = express.Router();
var mongoose = require('mongoose');
var Schema = mongoose.Schema;

const Film = require('../models/film');
const Actor = require('../models/actor');
const Genre = require('../models/genre');

const ERROR400 = 400;

router.get('/:type', function(req, res){
    var type = req.params.type;
    if(type === 'films' || type === 'actors' || type === 'genres'){
        if(req.originalUrl === ('/api/'+type))
            res.redirect('/api/'+type+'?page=1');

        var schema = new Schema();

        if(type === 'films')
            schema = Film;
        else if(type === 'actors')
            schema = Actor;
        else if(type === 'genres')
            schema = Genre;

        var reqPage = req.query.page;
        schema.count({}, function (err, count) {
            var skip = 4 * (reqPage - 1);
            var allpages = count / 4;
            if(count % 4 !== 0)
            {
                allpages++;
            }
            if(reqPage <= 0 || reqPage > allpages)
                res.redirect('/api/'+type);
            schema.find({},{},{limit:4, skip:skip})
                .then(function (doc) {
                    if(type === 'films'){
                        doc.forEach(item => {
                            item.poster = undefined;
                            item.screens = undefined;
                        });
                    }
                    else if(type === 'actors'){
                        doc.forEach(item => {
                            item.photos = undefined;
                        });
                    }
                    else if(type === 'genres'){}

                    res.json(doc);
                })
        })

    } else {
        var error = new Error();
        error.message = "Bad request";
        error.status = ERROR400;
        res.json(error);
    }
});

router.get('/search/films/:title', function (req, res) {
    var reqTitle = req.params.title;

    Film.findByTitle(reqTitle, function (err, doc) {
        if(doc) res.send(doc);
        else res.send(err);
    });
});

router.get('/:type/:_id', function (req, res) {
    var type = req.params.type;
    var id = req.params._id;

    if(type === 'films' || type === 'actors' || type === 'genres'){
        var schema = new Schema();

        if(type === 'films')
            schema = Film;
        else if(type === 'actors')
            schema = Actor;
        else if(type === 'genres')
            schema = Genre;

        schema.findOne({'_id':id})
            .then(function (doc) {
                if(doc && 0 !== doc.length){
                    if(type === 'films'){
                        doc.screens = undefined;
                    }
                    else if(type === 'actors'){
                        doc.photos = undefined;
                    }
                    else if(type === 'genres'){}

                    res.json(doc);
                } else {
                    var error = new Error();
                    err.message = "Not found";
                    err.status = ERROR400;
                    res.json(error);
                }
            })
            .catch(err => {
                err.message = "Invalid input";
                err.status = ERROR400;
                res.json(err)
            });
    } else {
        var error = new Error();
        error.message = "Bad request";
        error.status = 400;
        res.json(error);
    }
});

router.post('/genres', function (req, res) {
    var name = req.body.name.trim();
    if(!name || 0 === name.length){
        var error = new Error();
        error.status = ERROR400;
        error.message = 'One of required fields are empty';
        res.json(error).end();
    } else {
        Genre.findOne({'name':name})
            .then(function (doc) {
                if(doc && 0 !== doc.length){
                    var error = new Error();
                    error.status = ERROR400;
                    error.message = 'Such genre is already exist';
                    res.json(error).end();
                } else {
                    var genre = new Genre();
                    genre.name = name;
                    genre.save()
                        .then(function (doc) {
                            res.json(doc);
                        })
                        .catch(err => res.json(err)).end();
                }
            })
            .catch(err => res.json(err)).end();
    }
});

router.post('/actors', function (req, res) {
    req.checkBody('name', "Empty name").notEmpty();
    req.checkBody('birthdate', "Empty birthdate").notEmpty();
    req.checkBody('hometown', "Empty hometown").notEmpty();
    req.checkBody('roles', "Empty roles").notEmpty();

    var errors = req.validationErrors();
    if(errors){
        var err = new Error();
        err.message = "Invalid input";
        err.status = ERROR400;
        err.fields = errors;
        res.json(err).end();
    }

    var name = req.body.name;
    var hometown = req.body.hometown;
    var birthdate = req.body.birthdate;
    var roles = req.body.roles;

    Actor.findOne({'name':name})
        .then(function (doc) {
            if(doc){
                var err = new Error();
                err.message = "Such actor is already exist";
                err.status = ERROR400;
                res.json(err).end();
            } else {
                var actor = new Actor();

                actor.name = name;
                actor.birthdate = birthdate;
                actor.hometown = hometown;
                actor.roles = roles;

                actor.save()
                    .then(function (doc) {
                        res.json(doc);
                    })
                    .catch(err => res.json(err)).end();
            }
        })
        .catch(err => res.json(err).end());
});

router.post('/films', function (req, res) {
    req.checkBody('title', "Empty title").notEmpty();
    req.checkBody('director', "Empty director").notEmpty();
    req.checkBody('budget', "Empty budget").notEmpty();
    req.checkBody('budget', "Budget must be a number").isInt();
    req.checkBody('duration', "Empty duration").notEmpty();
    req.checkBody('duration', "Duration must be a number").isInt();
    req.checkBody('date', "Empty date").notEmpty();

    var errors = req.validationErrors();
    if(errors){
        var err = new Error();
        err.message = "Invalid input";
        err.status = ERROR400;
        err.fields = errors;
        res.json(err).end();
    }

    var title = req.body.title.trim();
    var director = req.body.director;
    var budget = req.body.budget;
    var duration = req.body.duration;
    var date = req.body.date;

    Film.contains(title, function(contain){
        if(contain){
            var err = new Error();
            err.message = "Such film is already exist";
            err.status = ERROR400;
            res.json(err).end();
        } else {
            var film = new Film();

            film.title = title;
            film.director = director;
            film.budget = budget;
            film.duration = duration;
            film.date = date;

            Film.saveFilm(film, function (err, doc) {
                if(doc) res.json(doc);
                else res.json(err);
            });
        }
    });
});

router.delete('/:type/:_id', function (req, res) {
    var type = req.params.type;
    var id = req.params._id;

    if(type === 'films' || type === 'actors' || type === 'genres'){
        var schema = new Schema();

        if(type === 'films')
            schema = Film;
        else if(type === 'actors')
            schema = Actor;
        else if(type === 'genres')
            schema = Genre;

        schema.findOneAndRemove({'_id':id})
            .then(function (doc) {
                var response = {
                    status: "OK",
                    message: "Object successfully deleted",
                    id: doc._id,
                    name: doc.name,
                    title: doc.title
                };
                res.json(response).end();
            })
            .catch(err => res.json(err).end());
    } else {
        var error = new Error();
        error.message = "Bad request";
        error.status = ERROR400;
        res.json(error).end();
    }
});

router.put('/genres/:_id', function (req, res) {
    var newName = req.body.name;
    var id = req.params._id;

    if(newName && 0 !== newName.length){
        Genre.findOne({'_id':id})
            .then(function (doc) {
                if(!doc || 0 === doc.length){
                    var error = new Error();
                    error.message = "No such object";
                    error.status = ERROR400;
                    res.json(error).end();
                } else {
                    doc.name = newName || doc.name;

                    doc.save()
                        .then(doc => res.json(doc).end())
                        .catch(err => {
                            err.message = "Invalid input";
                            res.json(err).end();
                        })
                }
            })
            .catch(err => {
                err.message = "Invalid input";
                res.json(err).end();
            });
    } else {
        var error = new Error();
        error.message = "Bad request";
        error.status = ERROR400;
        res.json(error).end();
    }
});

router.put('/actors/:_id', function (req, res) {

    var newName = req.body.name;
    var newHometown = req.body.hometown;
    var newBirthdate = req.body.birthdate;
    var newRoles = req.body.roles;

    var id = req.params._id;

    Actor.findOne({'_id':id})
        .then(function (doc) {
            if(doc && 0 !== doc.length){
                doc.name = newName || doc.name;
                doc.hometown = newHometown || doc.hometown;
                doc.birthdate = newBirthdate || doc.birthdate;
                doc.roles = newRoles || doc.roles;

                doc.save()
                    .then(doc => res.json(doc).end())
                    .catch(err => {err.message="Invalid input"; res.json(err).end()});
            } else {
                var error = new Error();
                error.message = "No such object";
                error.status = ERROR400;
                res.json(error).end();
            }
        })
        .catch(err => res.json(err).end());
});

router.put('/films/:_id', function (req, res) {

    var newTitle = req.body.title;
    var newDirector = req.body.director;
    var newBudget = req.body.budget;
    var newDuration = req.body.duration;
    var newDate = req.body.date;

    var id = req.params._id;

    Film.findOne({'_id':id})
        .then(function (doc) {
            if(doc && 0 !== doc.length){
                doc.title = newTitle || doc.title;
                doc.director = newDirector || doc.director;
                doc.budget = newBudget || doc.budget;
                doc.duration = newDuration || doc.duration;
                doc.date = newDate || doc.date;

                doc.save()
                    .then(doc => res.json(doc).end())
                    .catch(err => {err.message="Invalid input"; res.json(err).end()});
            } else {
                var error = new Error();
                error.message = "No such object";
                error.status = ERROR400;
                res.json(error).end();
            }
        })
        .catch(err => res.json(err).end());
});

module.exports = router;