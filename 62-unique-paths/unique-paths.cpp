class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return dp(m - 1, n - 1, memo);
    }

    int dp(int m, int n, vector<vector<int>>& memo) {
        if (!m || !n)
            return 1;

        if (memo[m][n])
            return memo[m][n];

        memo[m][n] = dp(m - 1, n, memo) + dp(m, n - 1, memo);
        return memo[m][n];
    }
};