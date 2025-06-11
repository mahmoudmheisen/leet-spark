class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxElement = 0;
        int maxElementCount = INT_MIN;
        unordered_map<int, int> frequency;

        for (int num : nums) {
            frequency[num]++;
        }

        for (auto pair : frequency) {
            if(pair.second > maxElementCount) {
                maxElementCount = pair.second;
                maxElement = pair.first;
            }
        }

        return maxElement;
    }
};