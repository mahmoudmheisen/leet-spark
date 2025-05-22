
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for(int i = 0; i < nums.size();i++) {
            ht.insert({nums[i], i});
        }

        int i = 0;
        int idx;
        for(; i < nums.size(); i++) {
            int search = target - nums[i];
            if(ht.find(search) == ht.end()) continue;
            idx = ht[search];
            if(i == idx) continue;
            break;
        }

        return {i, idx};
    }
};