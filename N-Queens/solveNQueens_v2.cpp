class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if (n < 1)
        	return res;
        vector<int> usedRows(n, -1);
        vector<vector<bool> > used(n, vector<bool>(n, false));
        findNQueens(0, n, used, usedRows, res);
        return res;
    }

    void findNQueens(int currRow, int n, vector<vector<bool> > &used, vector<int> &usedRows, vector<vector<string> > &res) {
    	if (currRow == n) {
    		vector<string> oneRes;
    		for (int i = 0; i < n; i++) {
    			string oneRow;
    			for (int j = 0; j < n; j++) {
    				oneRow += used[i][j] ? 'Q' : '.';
    			}
    			oneRes.push_back(oneRow);
    		}
    		res.push_back(oneRes);
    		return;
    	}
    	for (int i = 0; i < n; i++) {
    		if (isValid(currRow, i, usedRows)) {
    			used[currRow][i]  = true;
    			usedRows[currRow] = i;
    			findNQueens(currRow+1, n, used, usedRows, res);
    			used[currRow][i]  = false;
    			usedRows[currRow] = -1;
    		}
    	}
    }

    bool isValid(int currRow, int currCol, vector<int> &usedRows) {
    	for (int i = 0; i < currRow; i++) {
    		if (usedRows[i] == currCol || abs(currRow-i) == abs(currCol-usedRows[i]))
    			return false;
    	}
    	return true;
    }
};