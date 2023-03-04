class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {   
        sort(score.begin(), score.end(), [&](vector<int> r1, vector<int> r2) {
            return r1[k] > r2[k];
        });
        return score;
    }
};