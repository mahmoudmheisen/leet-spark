class Solution {
public:
    bool halvesAreAlike(string s) {
        int h1 = 0, h2 = 0;
        int n = s.size();
        unordered_map <char, bool> m;
        int l = 0, r = n - 1;
        
        m['a'] = 1;
        m['e'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['u'] = 1;
        
        while(l < r) {
            if(m[tolower(s[l++])]) h1++; 
            if(m[tolower(s[r--])]) h2++; 
        }
        
        return h1 == h2;
    }
};
