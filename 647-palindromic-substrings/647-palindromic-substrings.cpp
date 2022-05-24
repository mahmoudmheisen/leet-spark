class Solution {
private:
  int getCount(string s, int l, int r) {
    int count = 0;
    
    while (l >= 0 && r < s.size() && s[l--] == s[r++]) {
      count++;
    }

    return count;
  }

  
public:
  int countSubstrings(string s) {
    int n = s.size();
    int res = 0;
    
    if (!n || n == 1) return n;
    
    for (int i = 0; i < n; i++) {
      res += getCount(s, i, i);
      res += getCount(s, i, i + 1);
    }
    
    return res;
  }
};










