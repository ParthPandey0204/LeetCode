class Solution {
public:
    bool solve(vector<vector<char>>& board,
               vector<vector<int>>& rows,
               vector<vector<int>>& cols,
               vector<vector<int>>& boxes) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    int box = (i / 3) * 3 + (j / 3);

                    for (char ch = '1'; ch <= '9'; ch++) {
                        int num = ch - '1';

                        if (rows[i][num] || cols[j][num] || boxes[box][num])
                            continue;

                        board[i][j] = ch;
                        rows[i][num] = 1;
                        cols[j][num] = 1;
                        boxes[box][num] = 1;

                        if (solve(board, rows, cols, boxes))
                            return true;

                        board[i][j] = '.';
                        rows[i][num] = 0;
                        cols[j][num] = 0;
                        boxes[box][num] = 0;
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> cols(9, vector<int>(9, 0));
        vector<vector<int>> boxes(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int box = (i / 3) * 3 + (j / 3);

                    rows[i][num] = 1;
                    cols[j][num] = 1;
                    boxes[box][num] = 1;
                }
            }
        }

        solve(board, rows, cols, boxes);
    }
};