class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        prev.push_back(1);
        for (int row = 0; row < rowIndex; row++) {
        	vector<int> curr;
        	vector<int>::size_type size = prev.size();
        	for (vector<int>::size_type i = 0; i < size; i++) {
        		if (i == 0)
        			curr.push_back(1);
        		else
        			curr.push_back(prev[i-1] + prev[i]);
        	}
            curr.push_back(1);
        	prev = curr;
        }
        return prev;
    }
};