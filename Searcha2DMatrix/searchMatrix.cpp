class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty())
            return false;
        int rowIndex = findRow(matrix, 0, matrix.size()-1, target);
        if (rowIndex == matrix.size() || matrix[rowIndex][0] > target)
        	rowIndex--;
        if (rowIndex < 0)
        	return false;
        return findTarget(matrix, rowIndex, 0, matrix[rowIndex].size()-1, target);
    }

    int findRow(vector<vector<int>> &matrix, int first, int last, int target) {
    	if (first > last)
    		return first;
    	int rowIndex = (first + last) / 2;
    	if (matrix[rowIndex][0] == target)
    		return rowIndex;
    	if (matrix[rowIndex][0] < target)
    		return findRow(matrix, rowIndex+1, last, target);
    	else
    		return findRow(matrix, first, rowIndex-1, target);
    }

    bool findTarget(vector<vector<int>> &matrix, int rowIndex, int first, int last, int target) {
    	if (first > last)
    		return false;
    	int colIndx = (first + last) / 2;
    	if (matrix[rowIndex][colIndx] == target)
    		return true;
        if (matrix[rowIndex][colIndx] < target)
    		return findTarget(matrix, rowIndex, colIndx+1, last, target);
    	else if (matrix[rowIndex][colIndx] > target)
    		return findTarget(matrix, rowIndex, first, colIndx-1, target);
    }
};