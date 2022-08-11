class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mst;
        map<char,char> mts;
        
        for(int i = 0; i < s.size(); i++) {
            char s1 = s[i], t1 = t[i];
            
            if(!mst.count(s1) && !mts.count(t1))  {
                mst[s1] = t1;
                mts[t1] = s1;
            } else if (mst[s1] != t1 || mts[t1] != s1) {
                return false;
            } 
        }
        
        return true;
    }
};