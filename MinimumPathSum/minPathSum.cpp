class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty())
            return 0;
        int prev[grid[0].size()];
        int curr[grid[0].size()];
        prev[0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++) {
        	prev[i] = prev[i-1]+grid[0][i];
        }
        for (int i = 0; i < grid[0].size(); i++) {
            curr[i] = prev[i];
        }
        for (int i = 1; i < grid.size(); i++) {
        	curr[0] = prev[0] + grid[i][0];
        	for (int j = 1; j < grid[i].size(); j++) {
        		curr[j] = min(curr[j-1], prev[j]) + grid[i][j];
        	}
            for (int j = 0; j < grid[i].size(); j++) {
                prev[j] = curr[j];
            }
        }
        return curr[grid[0].size()-1];
    }
};