class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> intersections;

        int firstP = 0;
        int secondP = 0;

        while (firstP < firstList.size() && secondP < secondList.size()) {
            vector<int> a, b;
            if (firstList[firstP][0] <= secondList[secondP][0]) {
                a = firstList[firstP];
                b = secondList[secondP];
            } else {
                a = secondList[secondP];
                b = firstList[firstP];
            }
            if (a[1] >= b[0]) {
                intersections.push_back({b[0], min(a[1], b[1])});
            }
            if (firstList[firstP][1] <= secondList[secondP][1]) {
                firstP++;
            } else {
                secondP++;
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