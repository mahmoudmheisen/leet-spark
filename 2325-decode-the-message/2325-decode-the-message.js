/**
 * @param {string} key
 * @param {string} message
 * @return {string}
 */
var decodeMessage = function(key, message) {
    var keySet = new Set(key);
    var newKey = [...keySet].filter(item => item !== " ");
    var letters = "abcdefghijklmnopqrstuvwxyz";
    var ans = "";
    
    for(var letter of message) {
        var idx = newKey.indexOf(letter);
        ans += (idx !== -1 ? letters[idx] : " ");
    }
    
    return ans;    
};
