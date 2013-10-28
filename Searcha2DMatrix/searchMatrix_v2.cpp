class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty())
        	return false;
        auto nrows = matrix.size();
        auto ncols = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[nrows-1][ncols-1])
        	return false;
        int i = 0;
        int j = nrows - 1;
        while (i <= j) {
        	int k = (i + j) / 2;
        	if (matrix[k][0] > target)
        		j = k - 1;
        	else if (matrix[k][0] < target)
        		i = k + 1;
        	else
        		return true;
        }
        int row = j;
        i = 0;
        j = ncols - 1;
        while (i <= j) {
        	int k = (i + j) / 2;
        	if (matrix[row][k] > target)
        		j = k - 1;
        	else if (matrix[row][k] < target)
        		i = k + 1;
        	else
        		return true;
        }
        return false;
    }
};