class Solution {
private:
  vector<int> solve(string s, map<string, vector<int>> &dp) {
    if (dp.find(s) != dp.end()) return dp[s];
    vector<int> ret;
    
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      
      if (c == '+' || c == '-' || c == '*') {
        vector<int> left = solve(s.substr(0, i), dp);
        vector<int> right = solve(s.substr(i + 1), dp);
        
        for (int l : left) {
          for (int r : right) {
            if (c == '+') ret.push_back(l+r);
            else if (c == '-') ret.push_back(l-r);
            else ret.push_back(l*r);
          }
        }
      }
    }
    
    if (!ret.size()) ret.push_back(stoi(s));
    dp[s] = ret;
    
    return ret;
  }
  
public:
  vector<int> diffWaysToCompute(string expression) {
    map<string, vector<int>> dp;
    return solve(expression, dp);
  }
};