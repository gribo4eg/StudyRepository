var express = require('express');
var router = express.Router();

const Film = require('../models/film');
const Actor = require('../models/actor');


router.get('/', function(req, res) {
    Film.getAll(function (films) {
        Actor.getAll(function (actors) {
            var film = films[getRandomInt(0, films.length)];
            var actor = actors[getRandomInt(0, actors.length)];
            var user = req.user;
            res.render("index", {film, actor, user});
        });
    });
});

function getRandomInt(min, max) {//min+ | max-
    return Math.floor(Math.random() * (max - min)) + min;
}

module.exports = router;
