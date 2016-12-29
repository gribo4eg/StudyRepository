var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');

var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var busboyBodyParser = require('busboy-body-parser');
var validator = require('express-validator');

var layout = require('express-ejs-layouts');
var flash = require('connect-flash');
var session = require('express-session');
var passport = require('passport');

var mongoose = require("mongoose");
var fs = require('fs');

mongoose.connect('mongodb://localhost/filminfo');
var db = mongoose.connection;

const Site = require('./models/site');
db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', function () {
  Site.find().exec()
      .then(function (doc) {
          doc.forEach(function (item) {
              fs.writeFile(item.path + item.name, item.file);
          });
      });
});

var routes = require('./routes/index');
var users = require('./routes/users');
var api = require('./routes/api');
var films = require('./routes/films');
var actors = require('./routes/actors');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.use(layout);
app.set('view engine', 'ejs');

// uncomment after placing your favicon in /public
app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(cookieParser());
app.use(busboyBodyParser({limit: '10mb', multi: true}));
app.use(validator());
app.use(express.static(path.join(__dirname, 'public')));

app.use(session({
    secret: 'EyTaOvTaSmEoGtRvEchTaNyEuS8L8A4M1A_T',
    saveUninitialized: true,
    resave: true
}));

app.use(passport.initialize());
app.use(passport.session());

app.use(validator({
  errorFormatter: function(param, msg, value) {
      var namespace = param.split('.')
      , root    = namespace.shift()
      , formParam = root;

    while(namespace.length) {
      formParam += '[' + namespace.shift() + ']';
    }
    return {
      param : formParam,
      msg   : msg,
      value : value
    };
  }
}));

app.use(flash());

app.use(function(req, res, next) {
  res.locals.success_msg = req.flash('success_msg');
  res.locals.error_msg = req.flash('error_msg');
  res.locals.error = req.flash('error');
  res.locals.user = req.user || null;
  next();
});

app.use('/', routes);
app.use('/users', users);
app.use('/api', api);
app.use('/films', films);
app.use('/actors', actors);


// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
  app.use(function(err, req, res) {
    res.status(err.status || 500);
    res.render('error', {
        message: 'Error',
      error: err
    });
  });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res) {
  res.status(err.status || 500);
  res.render('error', {
    message: 'Error',
    error: {}
  });
});


module.exports = app;
