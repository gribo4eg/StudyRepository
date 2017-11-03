/**
 * Created by sasha on 12.12.16.
 */
var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var siteSchema = new Schema({
    path: String,
    name: String,
    file: Buffer
}, {collection: 'siteinfo'});

module.exports = mongoose.model('Site', siteSchema);
