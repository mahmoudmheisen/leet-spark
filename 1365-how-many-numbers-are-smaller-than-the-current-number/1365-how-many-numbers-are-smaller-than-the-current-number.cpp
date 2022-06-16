class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      vector<int> res;
    
      for (int current : nums) {
        int count = 0;
        
        for (int num : nums) {
          if (current > num) count++;
        }
        
        res.push_back(count);
      }
      
      return res;
    }
};