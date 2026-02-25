class Solution {
public:
    bool solve(vector<vector<char>>& board,
               vector<vector<int>>& row,
               vector<vector<int>>& col,
               vector<vector<int>>& box) {
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                
                if (board[r][c] == '.') {
                    
                    for (int num = 1; num <= 9; num++) {
                        
                        int boxIndex = (r / 3) * 3 + (c / 3);
                        
                        if (row[r][num] == 0 &&
                            col[c][num] == 0 &&
                            box[boxIndex][num] == 0) {
                            
                            board[r][c] = num + '0';
                            row[r][num] = 1;
                            col[c][num] = 1;
                            box[boxIndex][num] = 1;
                            
                            if (solve(board, row, col, box))
                                return true;
                            
                            board[r][c] = '.';
                            row[r][num] = 0;
                            col[c][num] = 0;
                            box[boxIndex][num] = 0;
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> box(9, vector<int>(10, 0));
    
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '0';
                    int boxIndex = (r / 3) * 3 + (c / 3);
                    row[r][num] = 1;
                    col[c][num] = 1;
                    box[boxIndex][num] = 1;
                }
            }
        }
        
        solve(board, row, col, box);
    }
};