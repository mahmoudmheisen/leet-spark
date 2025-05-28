class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // reverse sort
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};