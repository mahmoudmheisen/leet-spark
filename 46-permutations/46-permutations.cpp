class Solution {
private:
  vector<vector<int>> res;
  
  void bt(vector<int>& nums, int n) {
    if (n == nums.size()) {
      res.push_back(nums);
      return;
    }
    
    for (int i = n; i < nums.size(); i++) {
      swap(nums[i], nums[n]);
      bt(nums, n+1);
      swap(nums[i], nums[n]);
    }
  }

public:
    vector<vector<int>> permute(vector<int>& nums) {
      bt(nums, 0);
      
      return res;
    }
};