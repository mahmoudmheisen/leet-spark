class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // bucket sort
        vector<int> res;
        
        // min, max
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());

        vector<int> bucket(max - min + 1);
        for (int i : nums) {
            bucket[i - min]++;
        }
        
        for (int i=0; i < bucket.size(); i++) {
            while(bucket[i]>0) {
                res.push_back(i+min);
                bucket[i]--;
            }
        }

        return res;
    }
};