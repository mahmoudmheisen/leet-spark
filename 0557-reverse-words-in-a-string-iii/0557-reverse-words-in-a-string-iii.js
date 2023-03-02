/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let str = "";
    let word = "";

    for(let i = 0; i < s.length; i++) {
        if(s[i] !== ' ') word = s[i] + word;
        else {
            str += word + " ";
            word = "";
        }
    }
    str += word;
    

    return str;
};