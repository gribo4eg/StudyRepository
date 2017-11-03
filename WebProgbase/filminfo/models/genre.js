var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var GenreSchema = new Schema({
    name: {type:String, required:true}
}, {collection: 'genres'});

var Genre = module.exports = mongoose.model('Genre', GenreSchema);

module.exports.addGenre = function (name, callback) {
    Genre.findOne({'name':name})
        .then(doc => {
            if(doc && 0!==doc.length && doc.name === name)
                callback(doc);
            else{
                var newgenre = new Genre();
                newgenre.name = name;
                newgenre.save()
                    .then(doc => callback(doc));
            }
        });
};