class Solution {

public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        bt(nums, current);
        return res;
    }

    void bt(vector<int>& nums, vector<int>& current) {
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }

        for (int num : nums) {
            if (find(current.begin(), current.end(), num) == current.end()) {
                current.push_back(num);

                bt(nums, current);

                current.pop_back();
            }
        }
    }
};