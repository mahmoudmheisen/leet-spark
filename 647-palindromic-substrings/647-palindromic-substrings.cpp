class Solution {
private:
  bool isPalindrome(string s, int l, int r) {
    while (l<r) {
      if(s[l] != s[r]) return false;
      
      l++;
      r--;
    }
    
    return true;
  }
  
public:
  int countSubstrings(string s) {
    int res = 0;
    
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        if (isPalindrome(s, i, j)) res++;
      }
    }
    
    return res;
  }
};










