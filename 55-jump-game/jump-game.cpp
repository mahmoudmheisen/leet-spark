class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= dist) {
                dist = i;
            }
        }

        return dist == 0;
    }
};