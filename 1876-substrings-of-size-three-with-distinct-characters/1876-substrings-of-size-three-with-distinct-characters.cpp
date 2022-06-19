class Solution {
public:
    bool check(string s, int start) {
      if (s[start] != s[start+1] && s[start+1] != s[start+2] && s[start+2] != s[start]) {
        return true;
      }
      
      return false;
    }
  
    int countGoodSubstrings(string s) {
      int k = 3;
      int n = s.size();
      
      if (n < k) return 0;
      
      int count = 0;
      
      for (int i = 0; i < s.size() - k + 1; i++) {
        if (check(s, i)) count++;
      }
      
      return count;
    }
};