class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum = 0, lsum = 0;
        
        for(int num : nums) rsum += num;
        
        for(int i = 0; i < nums.size(); i++) {
            rsum -= nums[i];
            if(lsum == rsum) return i;
            lsum += nums[i];
        }
        
        return -1;
    }
};