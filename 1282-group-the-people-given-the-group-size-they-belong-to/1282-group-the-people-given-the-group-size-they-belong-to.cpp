class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> res, tempGroups(n + 1);
        
        for (auto i = 0; i < n; i++) {
            int groupSize = groupSizes[i];
            tempGroups[groupSize].push_back(i);
            
            if (tempGroups[groupSize].size() == groupSize) {
                res.push_back(tempGroups[groupSize]);
                tempGroups[groupSize] = {};
            }
        }

        return res;
    }
};