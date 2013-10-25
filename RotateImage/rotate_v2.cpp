class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty())
        	return;
        int n = matrix.size();
        for (int layer = 0; layer < n / 2; layer++) {
        	int begin = layer;
        	int end   = n - begin - 1;
        	for (int i = begin; i < end; i++) {
        		int temp = matrix[begin][i];
        		matrix[begin][i] = matrix[n-i-1][begin];
        		matrix[n-i-1][begin] = matrix[end][n-i-1];
        		matrix[end][n-i-1] = matrix[i][end];
        		matrix[i][end] = temp;
        	}
        }
    }
};