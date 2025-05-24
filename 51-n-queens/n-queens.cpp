class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        set<int> c_set, d_set, ad_set;
        vector<string> current;
        bt(0, n, c_set, d_set, ad_set, res, current);

        return res;
    }

    void bt(int row, int n, set<int>& c_set, set<int>& d_set, set<int>& ad_set,
            vector<vector<string>>& res, vector<string>& current) {
        if (row == n) {
            res.push_back(current);
            return;
        }

        for (int col = 0; col < n; col++) {
            int diag = row - col;
            int anti_diag = row + col;

            if (c_set.count(col) || d_set.count(diag) ||
                ad_set.count(anti_diag)) {
                continue;
            }

            c_set.insert(col);
            d_set.insert(diag);
            ad_set.insert(anti_diag);

            string row_str = string(n,'.');
            row_str[col] = 'Q';
            current.push_back(row_str);

            bt(row + 1, n, c_set, d_set, ad_set, res, current);

            c_set.erase(col);
            d_set.erase(diag);
            ad_set.erase(anti_diag);
            current.pop_back();
        }
    }
};