class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size() < 26) return false;
        map<int, int> m;
        
        for(char c: s) {
            m[c - 97]++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(m[i] == 0) return false;
        }
        
        return true;
    }
};