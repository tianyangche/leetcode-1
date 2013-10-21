class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows < 1)
        	return res;
        vector<int> prev;
        prev.push_back(1);
        res.push_back(prev);
        if (numRows == 1)
        	return res;
        prev.push_back(1);
        res.push_back(prev);
        if (numRows == 2)
        	return res;
        for (int i = 2; i < numRows; i++) {
        	vector<int> curr;
        	curr.push_back(1);
        	for (int j = 0; j < i-1; j++) {
        		curr.push_back(prev[j] + prev[j+1]);
        	}
        	curr.push_back(1);
        	res.push_back(curr);
        	prev = curr;
        }
        return res;
    }
};