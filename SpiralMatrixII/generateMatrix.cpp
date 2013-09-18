class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res;
        if (n < 1)
            return res;
        int beginX = 0;
        int beginY = 0;
        int endX   = n - 1;
        int endY   = n - 1;
        int val    = 1;
        int val2   = n * n;
        vector<int> temp;
        for (int j = 0; j < n; j++)
            temp.push_back(0);
        for (int i = 0; i < n; i++) {
        	res.push_back(temp);
        }
        while (true) {
        	for (int i = beginX; i <= endX; i++)
        		res[beginY][i] = val++;
        	beginY++;
        	if (beginY > endY)
        		break;
        	for (int i = beginY; i <= endY; i++)
        		res[i][endX] = val++;
        	endX--;
        	if (beginX > endX)
        		break;
        	for (int i = endX; i >= beginX; i--)
        		res[endY][i] = val++;
        	endY--;
        	if (beginY > endY)
        		break;
        	for (int i = endY; i >= beginY; i--)
        		res[i][beginX] = val++;
        	beginX++;
        	if (beginX > endX)
        		break;
        }
        return res;
    }
};