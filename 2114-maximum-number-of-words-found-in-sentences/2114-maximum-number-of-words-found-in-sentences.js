/**
 * @param {string[]} sentences
 * @return {number}
 */
var mostWordsFound = function(sentences) {
    var lengths = [];
    
    for(let sentence of sentences) {
        lengths.push(sentence.split(" ").length);
    }
    
    return Math.max(...lengths);
};