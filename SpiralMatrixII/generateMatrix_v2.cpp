class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        if (n < 1)
        	return res;
        
        int beginX = 0;
        int endX   = n - 1;
        int beginY = 0;
        int endY   = n - 1;
        int val    = 1;

        while (true) {
        	for (int i = beginX; i <= endX; i++)
        		res[beginY][i] = val++;
        	if (++beginY > endY)
        		break;
        	for (int i = beginY; i <= endY; i++)
        		res[i][endX] = val++;
        	if (--endX < beginX)
        		break;
        	for (int i = endX; i >= beginX; i--)
        		res[endY][i] = val++;
        	if (--endY < beginY)
        		break;
        	for (int i = endY; i >= beginY; i--)
        		res[i][beginX] = val++;
        	if (++beginX > endX)
        		break;
        }

        return res;
    }
};