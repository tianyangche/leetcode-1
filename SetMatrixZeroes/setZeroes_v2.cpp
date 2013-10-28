class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty())
        	return;
        
        bool zeroinrow = false;
        bool zeroincol = false;
        int nrows = matrix.size();
        int ncols = matrix[0].size();
        
        for (int i = 0; i < nrows; i++) {
        	if (matrix[i][0] == 0) {
        		zeroincol = true;
        		break;
        	}
        }
        for (int i = 0; i < ncols; i++) {
        	if (matrix[0][i] == 0) {
        		zeroinrow = true;
        		break;
        	}
        }

        for (int i = 1; i < nrows; i++) {
        	for (int j = 1; j < ncols; j++) {
        		if (matrix[i][j] == 0) {
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }

        for (int i = 1; i < nrows; i++) {
        	if (matrix[i][0] == 0) {
        		for (int j = 1; j < ncols; j++) {
        			matrix[i][j] = 0;
        		}
        	}
        }
        for (int j = 1; j < ncols; j++) {
        	if (matrix[0][j] == 0) {
        		for (int i = 1; i < nrows; i++) {
        			matrix[i][j] = 0;
        		}
        	}
        }

        if (zeroinrow) {
        	for (int i = 0; i < ncols; i++) {
        		matrix[0][i] = 0;
        	}
        }
        if (zeroincol) {
        	for (int i = 0; i < nrows; i++) {
        		matrix[i][0] = 0;
        	}
        }
    }
};