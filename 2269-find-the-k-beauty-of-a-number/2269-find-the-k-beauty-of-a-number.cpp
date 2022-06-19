class Solution {
public:
    int divisorSubstrings (int num, int k) {
      int count = 0;
      string s = to_string(num);
      int n = s.size();
      
      if (n < k) return 0;
      
      string temp = "";
      for (int i = 0; i < n; i++) {
        temp += s[i];
        
        if (temp.size() == k) {
          int x = stoi(temp);
          
          if (x && num % x == 0) count++;
          temp.erase(0, 1);
        }
      }
      
      return count;
    }
};