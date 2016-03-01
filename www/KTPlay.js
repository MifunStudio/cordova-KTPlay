var exec = require('cordova/exec'),

module.exports = {
    init: function(appid, appSecret, successCallback, errorCallback) {
        exec(successCallback, errorCallback, "KTPlay", "init", [appid, appSecret]);
    }
    showCommunity: function(successCallback, errorCallback) {
        exec(successCallback, errorCallback, "KTPlay", "showCommunity", []);
    }
};
