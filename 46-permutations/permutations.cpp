class Solution {
private:
  vector<vector<int>> res;
  
  void bt(vector<int>& nums, int level) {
    if (level == nums.size()) {
      res.push_back(nums);
      return;
    }
    
    for (int i = level; i < nums.size(); i++) {
      swap(nums[i], nums[level]);
      bt(nums, level+1);
      swap(nums[i], nums[level]);
    }
  }

public:
    vector<vector<int>> permute(vector<int>& nums) {
      bt(nums, 0);
      
      return res;
    }
};