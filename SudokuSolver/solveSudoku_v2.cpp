class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        if (board.empty())
            return;
        solve(board);
    }

    bool solve(vector<vector<char> > &board) {

        vector<vector<char> >::size_type nrows = board.size();
        vector<vector<char> >::size_type ncols = board[0].size();

        for (vector<vector<char> >::size_type i = 0; i < nrows; i++) {
            for (vector<vector<char> >::size_type j = 0; j < ncols; j++) {
                if (board[i][j] == '.') {
                    for (unsigned int val = 1; val <= 9; val++) {
                        board[i][j] = val + '0';
                        if (isValid(board, i, j)) {
                            if (solve(board))
                                return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(vector<vector<char> > &board, vector<vector<char> >::size_type row, vector<vector<char> >::size_type col) {

        vector<bool> used(10, false);
        for (vector<vector<char> >::size_type i = 0; i < board.size(); i++) {
            if (board[i][col] != '.') {
                if (used[board[i][col]-'0'])
                    return false;
                else
                    used[board[i][col]-'0'] = true;
            }
        }

        used = vector<bool>(10, false);
        for (vector<vector<char> >::size_type i = 0; i < board[0].size(); i++) {
            if (board[row][i] != '.') {
                if (used[board[row][i]-'0'])
                    return false;
                else
                    used[board[row][i]-'0'] = true;
            }
        }

        used = vector<bool>(10, false);
        vector<vector<char> >::size_type row_begin = row / 3 * 3;
        vector<vector<char> >::size_type col_begin = col / 3 * 3;
        for (vector<vector<char> >::size_type i = row_begin; i < row_begin + 3; i++) {
            for (vector<vector<char> >::size_type j = col_begin; j < col_begin + 3; j++) {
                if (board[i][j] != '.') {
                    if (used[board[i][j]-'0'])
                        return false;
                    else
                        used[board[i][j]-'0'] = true;
                }
            }
        }

        return true;
    }
};