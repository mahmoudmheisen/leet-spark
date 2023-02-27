class Solution {
private:
    void count(vector<vector<int>>& grid, bool countRow, vector<int>& zeros, vector<int>& ones) {
        int m = grid.size();
        int n = grid[0].size();

        int k = countRow ? m : n;
        int l = countRow ? n : m;

        for(int i = 0; i < k; i++) {
            int s0 = 0;
            int s1 = 0;

            for(int j = 0; j < l; j++) {
                int val = countRow ? grid[i][j] : grid[j][i];
                s0 += val == 0 ? 1 : 0;
                s1 += val;
            }
            zeros.push_back(s0);
            ones.push_back(s1);
        }
    }

public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> diff;
        vector<int> r0, r1, c0, c1;
    
        count(grid, true, r0, r1);
        count(grid, false, c0, c1);

        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            vector<int> vec;
            for(int j = 0; j < n; j++) {
                vec.push_back(r1[i] + c1[j] - r0[i] - c0[j]);
            }
            diff.push_back(vec);
        }
        
        return diff;
    }
};