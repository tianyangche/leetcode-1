struct Area {
	int height;
	int width;
	Area(int h, int w) : height(h), width(w) {}
};

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty())
        	return 0;
        int nrows = matrix.size();
        int ncols = matrix[0].size();
        vector<int> heights(ncols, 0);
        int maxArea = 0;
        for (int i = 0; i < nrows; i++) {
        	for (int j = 0; j < ncols; j++) {
        		heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
        	}
        	maxArea = max(maxArea, area(heights));
        }
        return maxArea;
    }

    int area(vector<int> heights) {
    	stack<Area> recs;
    	int maxArea = 0;
    	for (vector<int>::size_type i = 0; i < heights.size(); i++) {
    		if (recs.empty() || heights[i] > recs.top().height) {
    			recs.push(Area(heights[i], 1));
    		} else {
    			int minHeight = INT_MAX;
    			int newWidth  = 0;
    			while (!recs.empty() && recs.top().height >= heights[i]) {
    				Area theArea = recs.top();
    				recs.pop();
    				minHeight = min(minHeight, theArea.height);
    				newWidth += theArea.width;
    				maxArea = max(maxArea, minHeight*newWidth);
    			}
    			recs.push(Area(heights[i], ++newWidth));
    		}
    	}
    	int minHeight = INT_MAX;
    	int newWidth  = 0;
    	while (!recs.empty()) {
    		Area theArea = recs.top();
    		recs.pop();
    		minHeight = min(minHeight, theArea.height);
    		newWidth += theArea.width;
    		maxArea = max(maxArea, minHeight*newWidth);
    	}
    	return maxArea;
    }
};