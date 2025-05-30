class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> current = merged.back();
            vector<int> next = intervals[i];
            if (current[1] >= next[0]) {
                merged.pop_back();
                vector<int> newCurrent = {current[0], max(current[1], next[1])};
                merged.push_back(newCurrent);
            } else {
                merged.push_back(next);
            }
        }

        return merged;
    }
};