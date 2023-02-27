class Solution {
private:
    int maxIdx(vector<int>& nums) {
        int idx = 0;
        int max = nums[idx];
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) {
                idx = i;
                max = nums[i];
            }
        }
        
        return idx;
    }

public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;

        for(int i = k; i > 0; i--) {
            int idx = maxIdx(gifts);
            gifts[idx] = floor(sqrt(gifts[idx]));          
        }
        
        for(int num : gifts) sum += num;
        
        return sum;
    }
};