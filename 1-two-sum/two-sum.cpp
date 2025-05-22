
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for(int i = 0; i < nums.size();i++) {
            ht.insert({nums[i], i});
        }

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(ht.find(complement) != ht.end() && i != ht[complement]) {
                return {i, ht[complement]};
            }
        }

        return {};
    }
};