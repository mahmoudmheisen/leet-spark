class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] - '0' == 1) {
                    dfs(grid, r, c);
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        grid[r][c] = '2';

        for (vector<int> dir : dirs) {
            if (isValidLocation(grid, r, c, dir)) {
                dfs(grid, r + dir[0], c + dir[1]);
            }
        }
    }

    bool isValidLocation(vector<vector<char>>& grid, int r, int c,
                         vector<int>& dir) {
        vector<int> newLoc(2);
        newLoc[0] = r + dir[0];
        newLoc[1] = c + dir[1];
        int m = grid.size();
        int n = grid[0].size();

        if (newLoc[0] < 0 || newLoc[0] >= m)
            return false;
        if (newLoc[1] < 0 || newLoc[1] >= n)
            return false;

        if (grid[newLoc[0]][newLoc[1]] - '0' != 1)
            return false;

        return true;
    }
};
