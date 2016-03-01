var exec = require('cordova/exec');

module.exports = {
    init: function(appid, appSecret, successCallback, errorCallback) {
        exec(successCallback, errorCallback, "KTPlay", "init", [appid, appSecret]);
    },
    showLoginView: function(successCallback, errorCallback) {
        exec(successCallback, errorCallback, "KTPlay", "showLoginView", []);
    },
    showCommunity: function(successCallback, errorCallback) {
        exec(successCallback, errorCallback, "KTPlay", "showCommunity", []);
    }
};
