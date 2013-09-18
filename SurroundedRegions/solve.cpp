class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty())
            return;
        vector<vector<bool>> marked;
        int nrows = board.size();
        int ncols = board[0].size();
        vector<bool> temp;
        for (int i = 0; i < ncols; i++) {
        	temp.push_back(false);
        }
        for (int i = 0; i < nrows; i++) {
        	marked.push_back(temp);
        }
        for (int i = 0; i < ncols; i++) {
        	if (board[0][i] == 'O' && !marked[0][i]) {
        		marked[0][i] = true;
        		mark(0, i, nrows, ncols, board, marked);
        	}
        	if (board[nrows-1][i] == 'O' && !marked[nrows-1][i]) {
        		marked[nrows-1][i] = true;
        		mark(nrows-1, i, nrows, ncols, board, marked);
        	}
        }
        for (int i = 0; i < nrows; i++) {
        	if (board[i][0] == 'O' && !marked[i][0]) {
        		marked[i][0] = true;
        		mark(i, 0, nrows, ncols, board, marked);
        	}
        	if (board[i][ncols-1] == 'O' && !marked[i][ncols-1]) {
        		marked[i][ncols-1] = true;
        		mark(i, ncols-1, nrows, ncols, board, marked);
        	}
        }
        for (int i = 1; i < nrows; i++) {
        	for (int j = 1; j < ncols; j++) {
        		if (board[i][j] == 'O' && !marked[i][j]) {
        			board[i][j] = 'X';
        			search(i, j, nrows, ncols, board, marked);
        		}
        	}
        }
    }

    void mark(int i, int j, int nrows, int ncols, vector<vector<char>> &board, vector<vector<bool>> &marked) {
    	if (i > 1 && board[i-1][j] == 'O' && !marked[i-1][j]) {
    		marked[i-1][j] = true;
    		mark(i-1, j, nrows, ncols, board, marked);
    	}
    	if (i < nrows-1 && board[i+1][j] == 'O' && !marked[i+1][j]) {
    		marked[i+1][j] = true;
    		mark(i+1, j, nrows, ncols, board, marked);
    	}
    	if (j > 1 && board[i][j-1] == 'O' && !marked[i][j-1]) {
    		marked[i][j-1] = true;
    		mark(i, j-1, nrows, ncols, board, marked);
    	}
    	if (j < ncols-1 && board[i][j+1] == 'O' && !marked[i][j+1]) {
    		marked[i][j+1] = true;
    		mark(i, j+1, nrows, ncols, board, marked);
    	}
    }

    void search(int i, int j, int nrows, int ncols, vector<vector<char>> &board, vector<vector<bool>> &marked) {
    	if (i > 1 && board[i-1][j] == 'O' && !marked[i-1][j]) {
    		board[i-1][j] = 'X';
    		search(i-1, j, nrows, ncols, board, marked);
    	}
    	if (i < nrows-1 && board[i+1][j] == 'O' && !marked[i+1][j]) {
    		board[i+1][j] = 'X';
    		search(i+1, j, nrows, ncols, board, marked);
    	}
    	if (j > 1 && board[i][j-1] == 'O' && !marked[i][j-1]) {
    		board[i][j-1] = 'X';
    		search(i, j-1, nrows, ncols, board, marked);
    	}
    	if (j < ncols-1 && board[i][j+1] == 'X' && !marked[i][j+1]) {
    		board[i][j+1] = 'X';
    		search(i, j+1, nrows, ncols, board, marked);
    	}
    }
};