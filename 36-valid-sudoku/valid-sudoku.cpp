class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rowsHT(9);
        vector<unordered_set<int>> colsHT(9);
        vector<unordered_set<int>> boxesHT(9);

        for(int r = 0; r<9; r++) {
            for (int c = 0; c < 9; c++) {
                int num = board[r][c] == '.' ? 0 : board[r][c] - '0';
                if (!num) continue;
                
                if(rowsHT[r].count(num)) return false;
                rowsHT[r].insert(num);

                if(colsHT[c].count(num)) return false;
                colsHT[c].insert(num);

                int boxR = r / 3;
                int boxC = c / 3;
                int boxIdx = boxC * 3 + boxR;
                if(boxesHT[boxIdx].count(num)) return false;

                boxesHT[boxIdx].insert(num);
            }
        }

        return true;
    }
};