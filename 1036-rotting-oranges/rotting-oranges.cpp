class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int minutes = 0;
        int freshCount = 0;

        queue<vector<int>> q;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    freshCount++;
                if (grid[r][c] == 2)
                    q.push({r, c});
            }
        }

        while (!q.empty() && freshCount > 0) {
            int levelSize = q.size();

            minutes++;
            for (int i = 0; i < levelSize; i++) {
                vector<int> cell = q.front();
                q.pop();

                for (vector<int> dir : dirs) {
                    vector<int> newCell = {dir[0] + cell[0], dir[1] + cell[1]};
                    if (isValidCell(newCell, grid)) {
                        grid[newCell[0]][newCell[1]] = 2;
                        freshCount--;
                        q.push({newCell[0], newCell[1]});
                    }
                }
            }
        }

        return freshCount ? -1 : minutes;
    }

    bool isValidCell(vector<int>& newCell, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (newCell[0] < 0 || newCell[0] >= m)
            return false;
        if (newCell[1] < 0 || newCell[1] >= n)
            return false;
        if (grid[newCell[0]][newCell[1]] != 1)
            return false;

        return true;
    }
};