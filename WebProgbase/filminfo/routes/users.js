var express = require('express');
var router = express.Router();
var passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;

const User = require('../models/user');

/* GET users listing. */
router.get('/', function(req, res) {res.redirect('/users/login')});

/*          REGISTRATION            */
router.get('/register', function(req, res){
    res.render('register', {errors:false});
});

router.post('/register', function(req, res){
    req.check('password1', 'Too short password').isLength({min:5});
    req.check('password1', 'Passwords are not equal').equals(req.body.password2);


    var errors = req.validationErrors();
    if(errors) res.render('register', {errors});
    else {
        User.getByNickname(req.body.usernickname.trim(), function(err, user){
            if(err) res.send(err);
            else if(user && user.length > 0){
                res.render('register', {errors:[{
                    param: "nickname",
                    msg: "Such user is already exists"
                }]});
            }
            else {
                var newUser = new User();
                newUser.avatar = undefined;
                newUser.birthdate = undefined;
                newUser.name = req.body.username.trim();
                newUser.nickname = req.body.usernickname.trim();
                newUser.password = req.body.password1;

                User.addUser(newUser, (err, user) => {
                    if(err) res.send(err);
                });
                req.flash('success_msg', 'Registration complete!');
                res.redirect('/users/login');
            }
        });
    }
});

router.get('/update', function (req, res) {
  var user = req.user;
  res.render('userupdate', {user});
});

router.post('/delete', function (req, res) {
    var user = req.user;
    User.deleteUser(user._id, function (err, doc) {
        if(doc) res.redirect('/users/logout');
        else res.render('error', {err});
    });
});

router.post('/update', function (req, res) {
    var id = req.user._id;
    var newname = req.body.username.trim();
    var newnick = req.body.usernickname.trim();
    var newbirth = req.body.birthdate;
    var newava = req.files.avatarka[0];
    var newpass = req.body.password1.trim();
    var confpass = req.body.password2.trim();

    var errors;
    if(newpass && confpass && 0!==newpass.length && 0!==confpass.length){
        req.check('password1', 'Too short password').isLength({min:5});
        req.check('password1', 'Passwords are not equal').equals(req.body.password2);
        errors = req.validationErrors();
    }

    if(errors) res.render('userupdate', {errors});
    else{
        User.getById(id, function (err, doc) {
            doc.name = newname || doc.name;
            doc.nickname = newnick || doc.nickname;
            doc.birthdate = newbirth || doc.birthdate;
            if(newava && 0!==newava.size) doc.avatar = newava.data;

            if (newpass && confpass && newpass===confpass &&
                0!==newpass.length && 0!==confpass.length){

                doc.password = newpass;
                User.addUser(doc, function (err, user) {
                    if(err) res.send(err);
                    else res.redirect('/users/userpage/'+user._id);
                })
            } else {
                User.updateUser(doc, function (err, user) {
                    if(err) res.send(err);
                    else res.redirect('/users/userpage/'+user._id);
                });
            }
        });
    }
});

passport.use(new LocalStrategy(
    function(username, password, done) {
        User.getByNickname(username, (err, user) => {
            if(err) throw err;
            if(!user){
                return done(null, false, {message: "Unknown User"});
            }

            User.validPass(password, user.password, (err, isMatch) => {
                if(err) res.send(err);
                if(isMatch){
                    return done(null, user);
                } else {
                    return done(null, false, {message: 'Invalid password'});
                }
            });
        });
    }
));

passport.serializeUser(function(user, done) {
    done(null, user.id);
});

passport.deserializeUser(function(id, done) {
    User.getById(id, function(err, user) {
        done(err, user);
    });
});

/*          LOGIN           */
router.get('/login', function(req, res){
    res.render('login', {errors:false, message:false});
});

router.post('/login', passport.authenticate('local', {successRedirect: '/', failureRedirect: '/users/login', failureFlash: true}),
    function(req, res) {
        res.redirect('/');
    });

router.get('/logout', function(req, res) {
    req.logout();

    req.flash('success_msg', 'You are logged out');
    res.redirect('/users/login');
});

router.get('/userpage/:_id', function(req, res){
    if(!req.user){
        var error = new Error();
        error.message = "Not found user";
        error.status = 404;
        res.render('error', {err:error});
    }
    var id = req.params._id;
    User.findOne({_id:id})
        .populate('subfilms')
        .then((doc) => {
            if(doc && req.user.statusUser){
                res.render('userpage', {user:doc});
            }else{
                var error = new Error("Not found user");
                error.status = 404;
                res.render('error', error);
            }
        })
        .catch((err) => res.render('error',{err}));
});


module.exports = router;
