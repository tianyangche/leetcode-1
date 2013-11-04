class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > maps(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (i == 0 || j == 0) {
        			maps[i][j] = 1;
        		} else {
        			maps[i][j] += maps[i-1][j] + maps[i][j-1];
        		}
        	}
        }
        return maps[m-1][n-1];
    }
};