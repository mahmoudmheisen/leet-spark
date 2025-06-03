enum cellState { EMPTY, FRESH, ROTTEN };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int mins = 0;
        int freshCount = 0;
        queue<pair<int, int>> rottenQueue;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == FRESH) {
                    freshCount++;
                }
                if (grid[r][c] == ROTTEN) {
                    rottenQueue.push({r, c});
                }
            }
        }

        while (!rottenQueue.empty() && freshCount) {
            int rottenSize = rottenQueue.size();

            for (int i = 0; i < rottenSize; i++) {
                pair<int, int> currentCell = rottenQueue.front();
                rottenQueue.pop();

                for (auto [dx, dy] : dirs) {
                    pair<int, int> newCell = {dx + currentCell.first,
                                              dy + currentCell.second};
                    if (isValidCell(grid, newCell)) {
                        freshCount--;
                        grid[newCell.first][newCell.second] = ROTTEN;
                        rottenQueue.push(newCell);
                    }
                }
            }
            mins++;
        }

        return !freshCount ? mins : -1;
    }

    int isValidCell(vector<vector<int>>& grid, pair<int, int>& newCell) {
        int m = grid.size();
        int n = grid[0].size();

        if (newCell.first < 0 || newCell.first >= m)
            return false;
        if (newCell.second < 0 || newCell.second >= n)
            return false;
        if (grid[newCell.first][newCell.second] != FRESH)
            return false;

        return true;
    }
};