class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty())
        	return false;
        int nrows = board.size();
        int ncols = board[0].size();
        vector<vector<bool> > used(nrows, vector<bool>(ncols, false));
        for (int i = 0; i < nrows; i++) {
        	for (int j = 0; j < ncols; j++) {
        		if (board[i][j] == word[0]) {
        			if (word.length() == 1)
        				return true;
        			if (exist(board, used, i, j, word, 1))
        				return true;
        		}
        	}
        }
        return false;
    }

    bool exist(vector<vector<char> > &board, vector<vector<bool> > &used, int i, int j, string word, int pos) {
    	if (pos == word.length())
    		return true;
    	used[i][j] = true;
    	if (i > 0 && board[i-1][j] == word[pos] && !used[i-1][j]) {
    		if (exist(board, used, i-1, j, word, pos+1))
    			return true;
    	}
    	if (i + 1 < board.size() && board[i+1][j] == word[pos] && !used[i+1][j]) {
    		if (exist(board, used, i+1, j, word, pos+1))
    			return true;
    	}
    	if (j > 0 && board[i][j-1] == word[pos] && !used[i][j-1]) {
    		if (exist(board, used, i, j-1, word, pos+1))
    			return true;
    	}
    	if (j + 1 < board[0].size() && board[i][j+1] == word[pos] && !used[i][j+1]) {
    		if (exist(board, used, i, j+1, word, pos+1))
    			return true;
    	}
    	used[i][j] = false;
    	return false;
    }
};