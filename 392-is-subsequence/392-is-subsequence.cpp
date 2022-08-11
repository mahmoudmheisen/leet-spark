class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0;
        char sc = s[k];
        for (int i = 0; i < t.size(); i++) {
            char tc = t[i];
            if(sc == tc) {
                sc = s[++k];
                continue;
            }
        }
        
        return k == s.size();
    }
};