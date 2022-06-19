class Solution {
public:
    int divisorSubstrings (int num, int k) {
      int count = 0;
      string s = to_string(num);
      int n = s.size();
      
      if (n < k) return 0;
      
      int beauty_window = stoi(s.substr(0, k));
      
      // initial window
      if (beauty_window && num % beauty_window == 0) count++;
      
      int factor = pow(10, k-1);
      
      for (int i = k; i < n; i++) {
        // update window
        beauty_window -= (s[i-k] - '0') * factor;
        beauty_window *= 10;
        beauty_window += (s[i] - '0');
        
        if (beauty_window && num % beauty_window == 0) count++;
      }
      
      return count;
    }
};