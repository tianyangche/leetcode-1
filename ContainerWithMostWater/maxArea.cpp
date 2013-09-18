struct boundary {
	int height;
	int width;
};

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while (i < j) {
        	int minheight = min(height[i], height[j]);
        	res = max(res, minheight*(j-i));
        	if (height[i] <= height[j])
        		i++;
        	else
        		j--;
        }
        return res;
    }
};