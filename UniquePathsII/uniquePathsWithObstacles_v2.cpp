class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty())
        	return 0;
        if (obstacleGrid[0][0] == 1)
        	return 0;
        int nrows = obstacleGrid.size();
        int ncols = obstacleGrid[0].size();
        vector<vector<int> > paths(nrows, vector<int>(ncols, 0));
        paths[0][0] = 1;
        for (int i = 1; i < nrows; i++) {
        	if (obstacleGrid[i][0] == 0)
        		paths[i][0] = 1;
        	else
        		break;
        }
        for (int i = 1; i < ncols; i++) {
        	if (obstacleGrid[0][i] == 0)
        		paths[0][i] = 1;
        	else
        		break;
        }
        for (int i = 1; i < nrows; i++) {
        	for (int j = 1; j < ncols; j++) {
        		if (obstacleGrid[i][j] == 0) {
        			paths[i][j] += paths[i-1][j] + paths[i][j-1];
        		}
        	}
        }
        return paths[nrows-1][ncols-1];
    }
};