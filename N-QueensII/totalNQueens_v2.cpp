class Solution {
public:
    int totalNQueens(int n) {
        if (n < 1)
        	return 0;
        vector<int> usedRows(n, -1);
        vector<vector<bool> > used(n, vector<bool>(n, false));
        int num = 0;
        findNQueens(0, n, usedRows, used, num);
        return num;
    }

    void findNQueens(int currRow, int n, vector<int> &usedRows, vector<vector<bool> > &used, int &num) {
    	if (currRow == n) {
    		num++;
    		return;
    	}
    	for (int i = 0; i < n; i++) {
    		if (isValid(currRow, i, usedRows)) {
    			usedRows[currRow] = i;
    			used[currRow][i]  = true;
    			findNQueens(currRow+1, n, usedRows, used, num);
    			usedRows[currRow] = -1;
    			used[currRow][i]  = false;
    		}
    	}
    }

    bool isValid(int currRow, int currCol, vector<int> &usedRows) {
    	for (int i = 0; i < currRow; i++) {
    		if (usedRows[i] == currCol || abs(usedRows[i] - currCol) == abs(i - currRow))
    			return false;
    	}
    	return true;
    }
};