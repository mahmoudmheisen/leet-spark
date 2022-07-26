class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size() < 26) return false;
        map<int, int> m;
        
        for(char c: s) {
            m[c - 97]++;
        }
        
        if(m.size() < 26) return false;
        
        return true;
    }
};