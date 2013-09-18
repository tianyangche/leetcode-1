class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty())
            return false;
        if (word.empty())
        	return true;
        int nrows = board.size();
        int ncols = board[0].size();
        if (nrows * ncols < word.length())
        	return false;
        vector<vector<bool> > map;
        vector<bool> init;
        for (int i = 0; i < ncols; i++)
        	init.push_back(false);
        for (int i = 0; i < nrows; i++)
        	map.push_back(init);
        for (int i = 0; i < nrows; i++) {
        	for (int j = 0; j < ncols; j++) {
        		if (board[i][j] == word[0] && !map[i][j]) {
        			map[i][j] = true;
        			if (findCom(i, j, board, word, 1, map))
        				return true;
        			map[i][j] = false;
        		}
        	}
        }
        return false;
    }

    bool findCom(int xi, int yi, vector<vector<char> > &board, string word, int pos, vector<vector<bool> > &map) {
    	if (pos == word.length()) {
    		return true;
    	} else {
    		if (xi > 0 && board[xi-1][yi] == word[pos] && !map[xi-1][yi]) {
    			map[xi-1][yi] = true;
    			if (findCom(xi-1, yi, board, word, pos+1, map))
    				return true;
    			map[xi-1][yi] = false;
    		}
    		if (xi < board.size()-1 && board[xi+1][yi] == word[pos] && !map[xi+1][yi]) {
    			map[xi+1][yi] = true;
    			if (findCom(xi+1, yi, board, word, pos+1, map))
    				return true;
    			map[xi+1][yi] = false;
    		}
    		if (yi > 0 && board[xi][yi-1] == word[pos] && !map[xi][yi-1]) {
    			map[xi][yi-1] = true;
    			if (findCom(xi, yi-1, board, word, pos+1, map))
    				return true;
    			map[xi][yi-1] = false;
    		}
    		if (yi < board[0].size()-1 && board[xi][yi+1] == word[pos] && !map[xi][yi+1]) {
    			map[xi][yi+1] = true;
    			if (findCom(xi, yi+1, board, word, pos+1, map))
    				return true;
    			map[xi][yi+1] = false;
    		}
    		return false;
    	}
    }
};