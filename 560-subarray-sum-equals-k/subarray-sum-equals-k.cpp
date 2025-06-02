class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        vector<int> prefix(n+1, 0);

        prefix[1] = nums[0];
        for (int i = 2; i < n+1; i++) {
            prefix[i] = prefix[i - 1] + nums[i-1];
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                if ((prefix[i] - prefix[j - 1]) == k) {
                    count++;
                }
            }
        }

        return count;
    }
};