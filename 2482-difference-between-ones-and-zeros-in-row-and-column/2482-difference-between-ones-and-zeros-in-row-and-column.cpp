class Solution {
private:
    void count(vector<vector<int>>& grid, bool countRow, vector<int>& ones) {
        int m = grid.size();
        int n = grid[0].size();

        int k = countRow ? m : n;
        int l = countRow ? n : m;

        for(int i = 0; i < k; i++) {
            int sum = 0;

            for(int j = 0; j < l; j++) {
                int val = countRow ? grid[i][j] : grid[j][i];
                sum += val;
            }
            ones.push_back(sum);
        }
    }

public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> diff;
        vector<int> r, c;
    
        count(grid, true, r);
        count(grid, false, c);

        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            vector<int> vec;
            for(int j = 0; j < n; j++) {
                vec.push_back(2 * r[i] + 2 * c[j] - n - m);
            }
            diff.push_back(vec);
        }
        
        return diff;
    }
};
