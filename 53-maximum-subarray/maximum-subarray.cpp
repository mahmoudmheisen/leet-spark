class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];

        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current = max(current + nums[i], nums[i]);
            max_sum = max(max_sum, current);
        }

        return max_sum;
    }
};