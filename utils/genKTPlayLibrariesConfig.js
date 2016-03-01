var fs = require('fs');
var path = require('path');

var base = 'src/ios/KTPlaySDK/Libraries/';
var basedir = __dirname + '/../';

var result = [];

function readdir(dir) {
    var files = fs.readdirSync(basedir + dir);
    files.forEach(function(file) {
        if(file.indexOf('.') === 0) {
            return;
        }
        if(fs.statSync(basedir + dir + file).isDirectory()) {
            readdir(dir + file + '/');
        } else {
            if(path.extname(file) === '.h') {
                result.push('<header-file src="' + dir + file + '" />');
            } else if(path.extname(file) === '.m') {
                result.push('<source-file src="' + dir + file + '" />');
            }
        }
    });
}

readdir(base);
result.forEach(function(item) {
    console.log(item);
});
