class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minV = *min_element(nums.begin(), nums.end());
        int maxV = *max_element(nums.begin(), nums.end());

        vector<int> count(maxV - minV + 1, 0);

        for (int num : nums) {
            count[num - minV] += 1;
        }

        int remain = k;
        for(int i = count.size()-1; i >=0; i--) {
            remain -= count[i];

            if(remain <= 0)
                return i + minV;
        }

        return -1;
    }
};