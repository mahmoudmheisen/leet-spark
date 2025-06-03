class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int startColor = image[sr][sc];
        if (startColor == color) {
            return image;
        }

        dfs(image, sr, sc, color, startColor);

        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int startColor) {
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        image[sr][sc] = color;

        for (auto [dx, dy] : dirs) {
            vector<int> newCell = {dx + sr, dy + sc};
            if(isValidCell(image, newCell, startColor)) {
                dfs(image, newCell[0], newCell[1], color, startColor);
            }
        }
    }

    bool isValidCell(vector<vector<int>>& image, vector<int>& newCell, int startColor) {
        int m = image.size();
        int n = image[0].size();

        if(newCell[0] < 0 || newCell[0] >= m) return false;
        if(newCell[1] < 0 || newCell[1] >= n) return false;
        if(image[newCell[0]][newCell[1]] != startColor) return false;

        return true;
    }
};