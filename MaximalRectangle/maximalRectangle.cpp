struct Rectangle {
    int height;
	int width;
	Rectangle(int h, int w) : height(h), width(w) {}
};

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty())
        	return 0;
        int height[matrix[0].size()];
        memset(height, 0, sizeof(int)*matrix[0].size());
        int res = 0;
        for (size_t i = 0; i < matrix.size(); i++) {
        	for (size_t j = 0; j < matrix[i].size(); j++) {
        		if (matrix[i][j] == '1') {
        			height[j]++;
        		} else {
        			height[j] = 0;
        		}
        	}
        	res = max(res, area(height, matrix[0].size()));
        }
        return res;
    }

    int area(int height[], int size) {
    	stack<Rectangle> rec;
    	int res = 0;
    	for (int i = 0; i < size; i++) {
    		if (i == 0) {
    			rec.push(Rectangle(height[i], 1));
    		} else {
    			if (height[i] >= height[i-1]) {
    				rec.push(Rectangle(height[i], 1));
    			} else {
    				int widths  = 0;
    				int heights = INT_MAX;
    				while (!rec.empty() && rec.top().height > height[i]) {
    					Rectangle rectangle = rec.top();
    					rec.pop();
    					widths += rectangle.width;
    					heights = min(heights, rectangle.height);
    					res 	= max(res, widths*heights);
    				}
    				rec.push(Rectangle(height[i], ++widths));
    			}
    		}
    	}
    	int widths  = 0;
    	int heights = INT_MAX;
    	while (!rec.empty()) {
    		Rectangle rectangle = rec.top();
    		rec.pop();
    		widths += rectangle.width;
    		heights = min(heights, rectangle.height);
    		res 	= max(res, widths*heights);
    	}
    	return res;
    }
};