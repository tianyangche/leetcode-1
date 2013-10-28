class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty())
        	return;
        int nrows = board.size();
        int ncols = board[0].size();
        vector<vector<bool> > marker(nrows, vector<bool>(ncols, false));
        for (int i = 0; i < nrows; i++) {
        	if (board[i][0] == 'O' && !marker[i][0]) {
        		marker[i][0] = true;
        		mark(i, 0, nrows, ncols, board, marker);
        	}
        	if (board[i][ncols-1] == 'O' && !marker[i][ncols-1]) {
        		marker[i][ncols-1] = true;
        		mark(i, ncols-1, nrows, ncols, board, marker);
        	}
        }
        for (int i = 0; i < ncols; i++) {
        	if (board[0][i] == 'O' && !marker[0][i]) {
        		marker[0][i] = true;
        		mark(0, i, nrows, ncols, board, marker);
        	}
        	if (board[nrows-1][i] == 'O' && !marker[nrows-1][i]) {
        		marker[nrows-1][i] = true;
        		mark(nrows-1, i, nrows, ncols, board, marker);
        	}
        }
        for (int i = 1; i < nrows; i++) {
        	for (int j = 1; j < ncols; j++) {
        		if (board[i][j] == 'O' && !marker[i][j]) {
        			board[i][j] = 'X';
        			dfs(i, j, nrows, ncols, board, marker);
        		}
        	}
        }
   	}

   	void mark(int i, int j, int nrows, int ncols, vector<vector<char> > &board, vector<vector<bool> > &marker) {
   		if (i > 0 && board[i-1][j] == 'O' && !marker[i-1][j]) {
   			marker[i-1][j] = true;
   			mark(i-1, j, nrows, ncols, board, marker);
   		}
   		if (i + 1 < nrows && board[i+1][j] == 'O' && !marker[i+1][j]) {
   			marker[i+1][j] = true;
   			mark(i+1, j, nrows, ncols, board, marker);
   		}
   		if (j > 0 && board[i][j-1] == 'O' && !marker[i][j-1]) {
   			marker[i][j-1] = true;
   			mark(i, j-1, nrows, ncols, board, marker);
   		}
   		if (j + 1 < ncols && board[i][j+1] == 'O' && !marker[i][j+1]) {
   			marker[i][j+1] = true;
   			mark(i, j+1, nrows, ncols, board, marker);
   		}
   	}
   	void dfs(int i, int j, int nrows, int ncols, vector<vector<char> > &board, vector<vector<bool> > &marker) {
   		if (i == 0 || i + 1 == nrows || j == 0 || j + 1 == ncols)
   			return;
   		if (board[i-1][j] == 'O' && !marker[i-1][j]) {
   			board[i-1][j] = 'X';
   			dfs(i-1, j, nrows, ncols, board, marker);
   		}
   		if (board[i+1][j] == 'O' && !marker[i+1][j]) {
   			board[i+1][j] = 'X';
   			dfs(i+1, j, nrows, ncols, board, marker);
   		}
   		if (board[i][j-1] == 'O' && !marker[i][j-1]) {
   			board[i][j-1] = 'X';
   			dfs(i, j-1, nrows, ncols, board, marker);
   		}

   		if (board[i][j+1] == 'O' && !marker[i][j+1]) {
   			board[i][j+1] = 'X';
   			dfs(i, j+1, nrows, ncols, board, marker);
   		}
   	}
};