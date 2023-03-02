class Solution {
public:
    string sub(string s, int start, int end, bool flip = false) {
        string res = "";

        for(int j = start; j < end; j++) {
            if(j < s.size()) res = flip ? s[j] + res : res + s[j];
        }

        return res;
    }

    string reverseStr(string s, int k) {
        string res = "";

        for(int i = 0; i < s.size(); i+=2*k) { 
            res += sub(s, i, i+k, true);
            res += sub(s, i+k, i+2*k);
        }

        return res; 
    }
};