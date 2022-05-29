class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < pow(2, nums.size()); i++) {
      string mask = bitset<10>(i).to_string();

      vector<int> vec;
      for (int j = 10-n; j < 10; j++) {
        if (mask[j] - '0') {
          vec.push_back(nums[j-10+n]);
        }
      }
      
      ans.push_back(vec);
    }

    return ans;
  }
};














