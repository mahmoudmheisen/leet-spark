class Solution {
public:
    int divisorSubstrings (int num, int k) {
      int count = 0;
      string s = to_string(num);
      int n = s.size();
      
      if (n < k) return 0;
      
      int current_beauty = stoi(s.substr(0, k));
      
      if (current_beauty && num % current_beauty == 0) count++;
      
      int factor = 1;
      for (int i = 1; i < k; i++) {
        factor *= 10;
      }
      
      for (int i = k; i < n; i++) {
        current_beauty -= (s[i-k] - '0')*factor;
        current_beauty *= 10;
        current_beauty += (s[i] - '0');
        if (current_beauty && num % current_beauty == 0) count++;
      }
      
      return count;
    }
};