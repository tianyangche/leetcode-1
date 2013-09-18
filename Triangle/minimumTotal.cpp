class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty())
            return 0;
        if (triangle.size() == 1)
        	return triangle[0][0];
        vector<int> prev;
        int res = INT_MAX;
        for (int i = 0; i < triangle.size(); i++)
        	prev.push_back(0);
        prev[0] = triangle[0][0];
        bool find = false;
        for (int i = 1; i < triangle.size(); i++) {
        	vector<int> curr;
        	for (int j = 0; j < triangle[i].size(); j++) {
        		if (j == 0)
        			curr.push_back(prev[0]+triangle[i][j]);
        		else if (j + 1 == triangle[i].size())
        			curr.push_back(prev[j-1]+triangle[i][j]);
        		else {
        			if (prev[j-1] < prev[j])
        				curr.push_back(prev[j-1]+triangle[i][j]);
        			else
        				curr.push_back(prev[j]+triangle[i][j]);
        		}
        		if (i + 1 == triangle.size() && curr[j] < res) {
        			res = curr[j];
        		}
        	}
        	prev = curr;
        }
        return res;
    }
};