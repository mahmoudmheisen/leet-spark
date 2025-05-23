class Solution {

public:
    vector<vector<int>> res;
    unordered_set<int> used;

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
            if (used.find(num) == used.end()) {
                current.push_back(num);
                used.insert(num);

                bt(nums, current);

                current.pop_back();
                used.erase(num);
            }
        }
    }
};