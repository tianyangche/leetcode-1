class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int beginX = 0;
        int endX   = matrix[0].size()-1;
        int beginY = 0;
        int endY   = matrix.size() - 1;
        while (true) {
        	for (int i = beginX; i <= endX; i++)
        		res.push_back(matrix[beginY][i]);
        	if (++beginY > endY)
        		break;
        	for (int i = beginY; i <= endY; i++)
        		res.push_back(matrix[i][endX]);
        	if (--endX < beginX)
        		break;
        	for (int i = endX; i >= beginX; i--)
        		res.push_back(matrix[endY][i]);
        	if (--endY < beginY)
        		break;
        	for (int i = endY; i >= beginY; i--)
        		res.push_back(matrix[i][beginX]);
        	if (++beginX > endX)
        		break;
        }
        return res;
    }
};