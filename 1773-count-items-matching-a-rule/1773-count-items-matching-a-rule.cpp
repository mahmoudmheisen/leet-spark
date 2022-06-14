class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
      int result = 0;
      int idx = 0;

      if (ruleKey[0] == 'c') idx = 1;
      if (ruleKey[0] == 'n') idx = 2;
      
      for (auto item : items) {
        if (item[idx] == ruleValue) result++;
      }
      
      return result;
    }
};