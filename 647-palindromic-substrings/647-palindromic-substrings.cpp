class Solution {
private:
  int getPalindromeAroundCenter(string s, int c) {
    int count = 1;
    
    count += getCount(s, c-1, c+1);
    count += getCount(s, c, c+1);
  
    return count;
  }
  
  int getCount(string s, int l, int r) {
    int count = 0;
    
    while (l >= 0 && r < s.size()) {
      if (s[l] != s[r]) break;
      
      count++;
      l--;
      r++;
    }

    return count;
  }

  
public:
  int countSubstrings(string s) {
    int res = 0;  
    for (int i = 0; i < s.size(); i++) {
      res += getPalindromeAroundCenter(s, i);
    }
    
    return res;
  }
};










