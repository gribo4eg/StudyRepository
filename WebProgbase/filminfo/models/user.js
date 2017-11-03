var mongoose = require('mongoose');
var Schema = mongoose.Schema;
var bcrypt = require('bcryptjs');

var Film = require('./film');

var UserSchema = new Schema({
    name: {type: String, required: true},
    password: {type:String, required: true},
    birthdate: {type:String, default:undefined},
    nickname: {type: String, required: true},
    subfilms: [{type: Schema.Types.ObjectId, ref:"Film"}],
    regdate: {type: Date, default: Date.now},
    avatar: {type: Buffer, default: undefined},
    statusAdmin: {type: Boolean, required: true, default: false},
    statusUser: {type: Boolean, required: true, default: true}
}, {collection: 'users'});

var User = module.exports = mongoose.model('User', UserSchema);

module.exports.deleteUser = function (userId, callback) {
    User.findOneAndRemove({'_id':userId}, callback);
};

module.exports.subFilm = function (userId, film, callback) {
    User.getById(userId, function (err, user) {
        user.subfilms.push(film);
        user.save()
            .then(doc => callback(null, true))
            .catch(err => callback(err, false))
    })
};

module.exports.unsubFilm = function (userId, film, callback) {
    console.log("unsubFilm:"+userId);
    User.getById(userId, function (err, user) {
        var newSub = [];
        for(var i=0; i<user.subfilms.length; i++){
            if(String(user.subfilms[i]) !== String(film._id)){
                newSub.push(user.subfilms[i])
            }
        }
        user.subfilms = newSub;
        user.save()
            .then(doc => callback(null, true))
            .catch(err => callback(err, false))
    });
};

module.exports.addUser = function(user, callback){
	bcrypt.genSalt(10, function(err, salt) {
	    bcrypt.hash(user.password, salt, function(err, hash) {
	        user.password = hash;
	        user.save(callback);
	    });
	});
};

module.exports.updateUser = function (user, callback) {
    user.save(callback);
};

module.exports.getByNickname = function(nickname, callback){
    User.findOne({nickname:nickname}, callback);
};

module.exports.getById = function(id, callback){
    User.findById(id, callback);
};

module.exports.validPass = function(checkPass, hash, callback){
    bcrypt.compare(checkPass, hash, function(err, isMatch) {
    	if(err) throw err;
    	callback(null, isMatch);
	});
};