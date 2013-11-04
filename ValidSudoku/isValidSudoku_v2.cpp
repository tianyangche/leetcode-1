class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.empty())
        	return true;
        vector<bool> checker(9, false);
        
        for (int i = 0; i < 9; i++) {
        	checker = vector<bool>(9, false);
        	for (int j = 0; j < 9; j++) {
        		if (board[i][j] != '.') {
        			if (checker[board[i][j] - '0'])
        				return false;
        			else
        				checker[board[i][j] - '0'] = true;
        		}
        	}
        }

        for (int j = 0; j < 9; j++) {
        	checker = vector<bool>(9, false);
        	for (int i = 0; i < 9; i++) {
        		if (board[i][j] != '.') {
        			if (checker[board[i][j] - '0'])
        				return false;
        			else
        				checker[board[i][j] - '0'] = true;
        		}
        	}
        }

        for (int i = 0; i < 9; i += 3) {
        	for (int j = 0; j < 9; j += 3) {
        		checker = vector<bool>(9, false);
        		for (int m = i; m < i + 3; m++) {
        			for (int n = j; n < j + 3; n++) {
        				if (board[m][n] != '.') {
							if (checker[board[m][n] - '0'])
								return false;
							else
								checker[board[m][n] - '0'] = true;
        				}
        			}
        		}
        	}
        }

        return true;
    }
};