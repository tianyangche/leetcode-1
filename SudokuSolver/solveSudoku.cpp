class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        if (board.empty())
            return;
        findSudoku(board);
    }

    bool findSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
            	if (board[i][j] == '.') {
        			for (int k = 0; k < 9; k++) {
        				board[i][j] = '1' + k;
        				if (isValid(board, i, j))
        					if (findSudoku(board))
        						return true;
            	    }
            	    board[i][j] = '.';
                	return false;
        		}
        	}
        }
        return true;
    }

    bool isValid(vector<vector<char> > &board, int i, int j) {
    	bool recs[9];
    	memset(recs, 0, sizeof(bool)*9);
    	for (int k = 0; k < 9; k++) {
    		if (board[i][k] != '.') {
    			if (recs[board[i][k]-'1'])
					return false;
    			recs[board[i][k]-'1'] = true;
    		} 
    	}
    	memset(recs, 0, sizeof(bool)*9);
    	for (int k = 0; k < 9; k++) {
    		if (board[k][j] != '.') {
    			if (recs[board[k][j]-'1'])
    				return false;
    			recs[board[k][j]-'1'] = true;
    		}
    	}
    	memset(recs, 0, sizeof(bool)*9);
    	int ki = i / 3 * 3;
    	int kj = j / 3 * 3;
    	for (int m = 0; m < 3; m++) {
    		for (int n = 0; n < 3; n++) {
    			if (board[ki+m][kj+n] != '.') {
    				if (recs[board[ki+m][kj+n]-'1'])
    					return false;
    				recs[board[ki+m][kj+n]-'1'] = true;
    			}
    		}
    	}
    	return true;
    }
};