class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int pre_prev = nums[0];
        int prev = max(nums[0], nums[1]);
        int current = prev;

        for (int i = 2; i < nums.size(); i++) {
            current = max(prev, nums[i] + pre_prev);
            pre_prev = prev;
            prev = current;
        }

        return current;
    }
};