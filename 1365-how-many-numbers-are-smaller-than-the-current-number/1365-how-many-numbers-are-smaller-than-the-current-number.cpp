class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      // count sorting
      vector<int> res(nums.size(), 0);
      
      vector<int> counts(101, 0);
      
      // bars for each number
      for (int i = 0; i < nums.size(); i++) {
        counts[nums[i]]++;
      }
      
      // less than current number
      for (int i = 1; i < counts.size(); i++) {
        counts[i] += counts[i-1];
      }
    
      // result
      for (int i = 0; i < nums.size(); i++) {
        // when nums[i] = 0 then it is 0
        if (nums[i]) res[i] = counts[nums[i]-1]; // - 1 because we need less than it only
      }
      
      return res;
    }
};