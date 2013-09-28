class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.empty())
            return false;
        bool checker[10];
        memset(checker, 0, sizeof(bool)*10);
        for (int i = 0; i < board.size(); i++) {
        	memset(checker, 0, sizeof(bool)*10);
        	for (int j = 0; j < board[0].size(); j++) {
        		if (board[i][j] != '.')
        			if (checker[board[i][j]-'0'])
        				return false;
        			else
        				checker[board[i][j]-'0'] = true;
        	}
        }
        for (int i = 0; i < board[0].size(); i++) {
        	memset(checker, 0, sizeof(bool)*10);
        	for (int j = 0; j < board.size(); j++) {
        		if (board[j][i] != '.')
        			if (checker[board[j][i]-'0'])
        				return false;
        			else
        				checker[board[j][i]-'0'] = true;
        	}
        }
        int i = 0;
        while (i < board.size()) {
        	int j = 0;
        	while (j < board[i].size()) {
        		int m = i;
        		memset(checker, 0, sizeof(bool)*10);
        		while (m < i + 3) {
        			int n = j;
        			while (n < j + 3) {
        				if (board[m][n] != '.')
        					if (checker[board[m][n]-'0'])
        						return false;
        					else
        						checker[board[m][n]-'0'] = true;
        				n++;
        			}
        			m++;
        		}
        		j += 3;
        	}
        	i += 3;
        }
        return true;
    }
};