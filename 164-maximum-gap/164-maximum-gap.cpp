class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0; 

        // bucket sort
        vector<int> res;

        // min, max
        int maxN = *max_element(nums.begin(), nums.end());
        int minN = *min_element(nums.begin(), nums.end());
        int n = nums.size();

        // create min and max bucket
        vector<int> min_bucket(n, INT_MAX);
        vector<int> max_bucket(n, INT_MIN);
        
        // set bucket size
        int bucketSize = (int) ceil((double)(maxN-minN)/(n - 1));
        if(!bucketSize) return 0;
        
        // fill buckets
        for (int num: nums) {
            int bucketIndex = (num - minN) / bucketSize;
            max_bucket[bucketIndex] = max(num, max_bucket[bucketIndex]);
            min_bucket[bucketIndex] = min(num, min_bucket[bucketIndex]);
        }
        
        // find max gap
        int maxGap = 0;
        int previous = max_bucket[0];

        for (int i=1; i<n; i++) {
            if (min_bucket[i] == INT_MAX) continue;
            
            maxGap = max(maxGap, min_bucket[i] - previous);
            previous = max_bucket[i];
        }
        
        return maxGap;
    }
};