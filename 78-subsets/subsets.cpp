class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        bt(nums, {}, res, 0);

        return res;
    }

    void bt(vector<int>& nums, vector<int> current, vector<vector<int>>& res,
            int level) {
        res.push_back(current);
        for (int i = level; i < nums.size(); i++) {
            current.push_back(nums[i]);
            bt(nums, current, res, i+1);
            current.pop_back();
        }
    }
};