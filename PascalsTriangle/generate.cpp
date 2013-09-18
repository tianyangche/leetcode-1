class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0)
        	return res;
       	vector<int> prev;
       	prev.push_back(1);
       	res.push_back(prev);
       	for (int i = 1; i < numRows; i++) {
       		vector<int> curr;
       		vector<int>::size_type size = prev.size();
       		for (vector<int>::size_type j = 0; j < size; j++) {
       			if (j == 0)
       				curr.push_back(1);
       			else
       				curr.push_back(prev[j-1] + prev[j]);
       		}
       		curr.push_back(1);
       		res.push_back(curr);
       		prev = curr;
       	}
       	return res;
    }
};