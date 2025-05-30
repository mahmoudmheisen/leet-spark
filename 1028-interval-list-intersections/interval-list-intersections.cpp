class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> intersections;

        int firstP = 0;
        int secondP = 0;

        while (firstP < firstList.size() && secondP < secondList.size()) {
            vector<int> current = firstList[firstP];
            vector<int> next = secondList[secondP];
            if (isOverlab(current, next)) {
                intersections.push_back(
                    {max(current[0], next[0]), min(current[1], next[1])});

                if (current[1] > next[1]) {
                    secondP++;
                } else {
                    firstP++;
                }
            } else {
                if (current[1] > next[1]) {
                    secondP++;
                } else {
                    firstP++;
                }
            }
        }

        return intersections;
    }

    bool isOverlab(vector<int>& current, vector<int>& next) {
        if (current[0] < next[0]) {
            return current[1] >= next[0];
        }
        return next[1] >= current[0];
    }
};