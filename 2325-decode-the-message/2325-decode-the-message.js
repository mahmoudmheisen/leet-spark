/**
 * @param {string} key
 * @param {string} message
 * @return {string}
 */
var decodeMessage = function(key, message) {
    var keySet = new Set(key.split(" ").join(""));
    var key2 = [...keySet].join("");
    var letters = "abcdefghijklmnopqrstuvwxyz";
    var ans = [];
    for(var l of message) {
        var a = key2.indexOf(l);
        ans.push(a !== -1 ? letters[a] : " ")
    }
    
    return ans.join("");    
};
