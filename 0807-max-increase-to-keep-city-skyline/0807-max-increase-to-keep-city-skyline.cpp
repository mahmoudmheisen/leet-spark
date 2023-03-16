class Solution {
private:
    vector<int> getRow(vector<vector<int>>& grid, int r) {
        return grid[r];
    }
    
    vector<int> getCol(vector<vector<int>>& grid, int c) {
        vector<int> ret;
        
        for(int i = 0; i < grid.size(); i++) {
           ret.push_back(grid[i][c]); 
        }
        
        return ret;
    }
    
    int getMax(vector<int> arr) {
        return *max_element(arr.begin(), arr.end());
    }
    
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                int h = grid[i][j];
                int maxRow = getMax(getRow(grid, i));
                int maxCol = getMax(getCol(grid, j));
                int minAdd = min(maxRow, maxCol);
                sum += (minAdd - h);
            }
        }
        
        return sum;
    }
};
