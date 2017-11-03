var mongoose = require("mongoose");
var Schema = mongoose.Schema;

const Film = require("./film");

var ActorSchema = new Schema({
    name: {type: String, required: true},
    birthdate: String,
    hometown: String,
    films: [{type: Schema.Types.ObjectId, ref:"Film"}],
    biography: String,
    photos:[String]
}, {collection: 'actors'});

var Actor = module.exports = mongoose.model("Actor", ActorSchema);

var notFound = {
    message:"Not found",
    status:404
};

module.exports.getAll = function (callback) {
    Actor.find()
        .populate('films')
        .then(doc => callback(doc))
};

module.exports.deleteActor = function (id, callback) {
    Actor.findOneAndRemove({'_id':id})
        .then(doc => callback(null, true))
        .catch(err => callback(false, null))
};

module.exports.getAllPagination = function (skip, callback) {
    Actor.find({},{},{limit:4, skip:skip})
        .then(doc => {
            callback(null, doc)
        })
        .catch(err => callback(notFound, null))
};

module.exports.findById = function (id, callback) {
    Actor.findOne({'_id': id})
        .populate('films')
        .then(doc => callback(null,doc))
        .catch(err => callback(notFound, null))
};

module.exports.findByName = function (title, callback) {
    Actor.findOne({'name':title})
        .populate('films')
        .then(doc => callback(null,doc))
        .catch(err => callback(notFound, null))
};

module.exports.getFilmsTitles = function (actor, callback) {
    var titles = [];
    if(actor.films && actor.films!==0) {
        actor.films.forEach(item => {
            titles.push(item.title);
        });
    }
    callback(titles);
};

module.exports.contains = function (name, callback) {
    Actor.findByName(name, function (err, doc) {
        if(doc && 0 !== doc.length) callback(true);
        else callback(false);
    });
};

module.exports.saveActor = function (actor, callback) {
    actor.save()
        .then(doc => callback(null, doc))
        .catch(err => callback(err, null))
};

module.exports.countOfActors = function (callback) {
    Actor.count({}, function (err, count) {
        callback(count);
    });
};