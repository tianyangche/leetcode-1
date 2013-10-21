class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if (rowIndex < 0)
        	return res;
        res.reserve(rowIndex+1);
        res.push_back(1);
        if (rowIndex == 0)
        	return res;
        res.push_back(1);
        if (rowIndex == 1)
        	return res;
        int k = 1;
        while (k < rowIndex) {
        	for (int i = 0; i < k; i++) {
        		res[i] += res[i+1];
        	}
        	res.insert(res.begin(), 1);
        	k++;
        }
        return res;
    }
};