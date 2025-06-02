class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> ht;

        ht[0] = 1;

        int currentSum = 0;
        for(int num : nums) {
            currentSum += num;

            if(ht.count(currentSum-k)) {
                count += ht[currentSum-k];
            }

            ht[currentSum]++;
        }

        return count;
    }
};
