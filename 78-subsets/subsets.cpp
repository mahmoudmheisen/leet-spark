class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        bt(nums, {}, res, 0);

        return res;
    }

    void bt(vector<int>& nums, vector<int> current, vector<vector<int>>& res,
            int level) {
        if (level == nums.size()) {
            res.push_back(current);
            return;
        }
        
        current.push_back(nums[level]);
        bt(nums, current, res, level+1);

        current.pop_back();
        bt(nums, current, res, level+1);
    }
};
