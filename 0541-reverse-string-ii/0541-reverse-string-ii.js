/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    let res = "";
    
    for(let i = 0; i < s.length; i+=2*k) { 
        let str = s.substring(i, i+k);
        
        let l = str.length-1;
        for(let j = 0; j < str.length; j++) {
            res += str[l--];
        }
        res += s.substring(i+k, i+2*k);
    }

    return res;
};
