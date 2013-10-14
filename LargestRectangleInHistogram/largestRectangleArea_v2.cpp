struct Area {
    int height;
    int width;
    Area(int h, int w) : height(h), width(w) {}
};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty())
            return 0;
        stack<Area> recs;
        int res = INT_MIN;
        for (int i = 0; i < height.size(); i++) {
            if (recs.empty() || height[i] >= recs.top().height) {
                recs.push(Area(height[i], 1));
            } else if (height[i] < recs.top().height) {
                int minHeight = INT_MAX;
                int newWidth  = 0;
                while (!recs.empty() && recs.top().height >= height[i]) {
                    Area theArea = recs.top();
                    recs.pop();
                    minHeight = min(minHeight, theArea.height);
                    newWidth += theArea.width;
                    res = max(res, minHeight*newWidth);
                }
                recs.push(Area(height[i], ++newWidth));
            }
        }
        int minHeight = INT_MAX;
        int newWidth  = 0;
        while (!recs.empty()) {
            Area theArea  = recs.top();
            recs.pop();
            minHeight = min(minHeight, theArea.height);
            newWidth += theArea.width;
            res = max(res, minHeight*newWidth);
        }
        return res;
    }
};