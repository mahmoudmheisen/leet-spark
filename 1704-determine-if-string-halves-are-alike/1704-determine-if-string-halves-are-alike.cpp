class Solution {
public:
    bool halvesAreAlike(string s) {
        int h1 = 0, h2 = 0;
        int n = s.size();
        unordered_map <char, bool> m;
        
        m['a'] = 1;
        m['e'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['u'] = 1;
        
        for(int i = 0; i < n; i++) {
            bool isVowel = m[tolower(s[i])];
            if(isVowel && i < n/2) h1++; 
            if(isVowel && i >= n/2) h2++; 
        }
        
        return h1 == h2;
    }
};
