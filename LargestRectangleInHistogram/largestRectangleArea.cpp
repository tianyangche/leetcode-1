struct Rectangle {
    int height;
	int width;
};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<Rectangle> rec;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
        	if (rec.empty()) {
        		Rectangle tmp;
        		tmp.height = height[i];
        		tmp.width  = 1;
        		rec.push(tmp);
        	} else {
        		if (height[i] < rec.top().height) {
        			int wd = 0;
        			int minHeight = INT_MAX;
        			while (!rec.empty() && rec.top().height > height[i]) {
        				Rectangle tmp = rec.top();
                        rec.pop();
        				minHeight = min(minHeight, tmp.height);
        				wd += tmp.width;
        				res = max(res, minHeight*wd);
        			}
        			Rectangle tmp;
        			tmp.height = height[i];
        			tmp.width  = ++wd;
        			rec.push(tmp);
        		} else {
        			Rectangle tmp;
        			tmp.height = height[i];
        			tmp.width  = 1;
        			rec.push(tmp);
        		}
        	}
        }
        int wd = 0;
        int minHeight = INT_MAX;
        while (!rec.empty()) {
        	Rectangle tmp = rec.top();
            rec.pop();
        	minHeight = min(minHeight, tmp.height);
        	wd += tmp.width;
        	res = max(res, minHeight*wd);
        }
    	return res;
    }
};