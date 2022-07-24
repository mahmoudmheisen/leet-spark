class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2*n);
        
        for (int i = 0; i < nums.size() * 2; i++) {
            if (i < n) res[i] = nums[i];
            else res[i]=nums[i-n];
            
        }
        
        return res;        
    }
};