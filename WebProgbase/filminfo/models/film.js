var mongoose = require('mongoose');
var Schema = mongoose.Schema;

const Genre = require('./genre');
const Actor = require('./actor');

var FilmSchema = new Schema({
    title: {type: String,required: true},
    director: {type: String,required: true},
    genres: [{type: Schema.Types.ObjectId, ref:"Genre"}],
    actors: [{type: Schema.Types.ObjectId, ref:"Actor"}],
    budget: Number,
    duration: Number,
    date: String,
    plot: String,
    poster: String,
    screens: [String],
    trailer: String
}, {collection: 'films'});

var Film = module.exports = mongoose.model('Film', FilmSchema);

var notFound = {
   message:"Not found",
   status:404
};

module.exports.getAll = function (callback) {
    Film.find()
        .populate('actors')
        .populate('genres')
        .then(doc => callback(doc))
};

module.exports.getAllPagination = function (skip, callback) {
    Film.find({},{},{limit:4, skip:skip})
        .then(doc => {
            callback(null, doc)
        })
        .catch(err => callback(notFound, null))
};

module.exports.findById = function (id, callback) {
    Film.findOne({'_id': id})
        .populate('actors')
        .populate('genres')
        .then(doc => callback(null,doc))
        .catch(err => callback(notFound, null))
};

module.exports.findByTitle = function (title, callback) {
    Film.findOne({'title': title})
        .populate('actors')
        .populate('genres')
        .then(doc => callback(null,doc))
        .catch(err => callback(notFound, null))
};

module.exports.contains = function (title, callback) {
    Film.findByTitle(title, function (err, doc) {
        if(doc && 0 !== doc.length) callback(true);
        else callback(false);
    });
};

module.exports.getActorsNames = function (film, callback) {
    var names = [];
    if(film.actors && film.actors!==0) {
        film.actors.forEach(item => {
            names.push(item.name);
        });
    }
    callback(names);
};

module.exports.getGenresNames = function (film, callback) {
    var names = [];
    if(film.genres && film.genres!==0) {
        film.genres.forEach(item => {
            names.push(item.name);
        });
    }
    callback(names);
};


module.exports.saveFilm = function (film, callback) {
    film.save()
        .then(doc => callback(null, doc))
        .catch(err => callback(err, null))
};

module.exports.deleteFilm = function (id, callback) {
    Film.findOneAndRemove({'_id':id})
        .then(doc => callback(null, true))
        .catch(err => callback(false, null))
};

module.exports.countOfFilms = function (callback) {
    Film.count({}, function (err, count) {
        callback(count);
    });
};
