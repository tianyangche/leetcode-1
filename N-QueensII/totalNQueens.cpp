class Solution {
public:
    int totalNQueens(int n) {
       int map[n];
       int result = 0;
       for (int i = 0; i < n; i++) {
           	map[0] = i;
       		findQueens(map, 1, n, result);
       }
    	return result;
    }

    void findQueens(int map[], int curr, int n, int &result) {
    	if (curr == n) {
    		result++;
    	} else {
    		for (int i = 0; i < n; i++) {
    			if (!isSafe(map, curr, i))
    				continue;
    			map[curr] = i;
    			findQueens(map, curr+1, n, result);
    			map[curr] = -1;
    		}
    	}
    }

    bool isSafe(int map[], int row, int col) {
    	for (int i = 0; i < row; i++) {
    		if (map[i] == col || abs(col-map[i]) == abs(row-i))
    			return false;
    	}
    	return true;
    }
};