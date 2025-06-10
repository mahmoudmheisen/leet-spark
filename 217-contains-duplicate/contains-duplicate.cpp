class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> distinct(nums.begin(), nums.end());

        return distinct.size() != nums.size();
    }
};