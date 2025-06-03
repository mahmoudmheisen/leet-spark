class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islandsCount = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] - '0' == 1) {
                    dfs(grid, r, c);
                    islandsCount++;
                }
            }
        }

        return islandsCount;
    };

    void dfs(vector<vector<char>>& grid, int r, int c) {
        // mark it as visited
        grid[r][c] = '2';
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto [dx, dy] : dirs) {
            vector<int> newCell = {dx + r, dy + c};
            if (isValidCell(grid, newCell)) {
                dfs(grid, newCell[0], newCell[1]);
            }
        }
    }

    bool isValidCell(vector<vector<char>>& grid, vector<int>& newCell) {
        int m = grid.size();
        int n = grid[0].size();

        // check the boundary
        if (newCell[0] < 0 || newCell[0] >= m)
            return false;
        if (newCell[1] < 0 || newCell[1] >= n)
            return false;

        // check if valid
        if (grid[newCell[0]][newCell[1]] - '0' != 1)
            return false;

        return true;
    }
};