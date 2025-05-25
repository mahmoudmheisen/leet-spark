class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int current = nums[0];

        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current = max(prev + nums[i], nums[i]);
            max_sum = max(max_sum, current);
            prev = current;
        }

        return max_sum;
    }
};