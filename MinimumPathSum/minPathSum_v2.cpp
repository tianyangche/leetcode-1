class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty())
        	return 0;
        int nrows = grid.size();
        int ncols = grid[0].size();
        vector<int> prev(ncols, -1);
        prev[0] = grid[0][0];
        for (int i = 1; i < ncols; i++) {
        	prev[i] = prev[i-1] + grid[0][i];
        }
        for (int i = 1; i < nrows; i++) {
        	vector<int> curr(ncols, -1);
        	for (int j = 0; j < ncols; j++) {
        		if (j > 0)
        			curr[j] = curr[j] == -1 ? curr[j-1]+grid[i][j] : min(curr[j], curr[j-1]+grid[i][j]);
        		curr[j] = curr[j] == -1 ? prev[j]+grid[i][j] : min(curr[j], prev[j]+grid[i][j]);
        	}
        	prev = curr;
        }
        return prev[ncols-1];
    }
};