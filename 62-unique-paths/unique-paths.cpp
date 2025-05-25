class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> current(n, 1);

        for(int r = 1; r < m; r++) {
            fill(current.begin(), current.end(), 1);
            for(int c = 1; c < n; c++) {
                current[c] = prev[c] + current[c-1];
            }
            prev = current;
        }

        return current[n-1];
    }
};