class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxLength = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                maxLength = max(maxLength, dfs(matrix, r, c, memo));
            }
        }
        return maxLength;
    }

    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo) {
        if(memo[r][c]) return memo[r][c];

        int maxCellLength = 1;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto [dx, dy] : dirs) {
            vector<int> newCell = {dx + r, dy + c};

            if (isValidCell(matrix, newCell, r, c)) {
                maxCellLength =
                    max(maxCellLength, 1 + dfs(matrix, newCell[0], newCell[1], memo));
            }
        }

        memo[r][c] = maxCellLength;
        return maxCellLength;
    }

    bool isValidCell(vector<vector<int>>& matrix, vector<int> newCell, int r, int c) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(newCell[0] < 0 || newCell[0] >= m) return false;
        if(newCell[1] < 0 || newCell[1] >= n) return false;
        if(matrix[newCell[0]][newCell[1]] <= matrix[r][c]) return false;

        return true;
    }
};
