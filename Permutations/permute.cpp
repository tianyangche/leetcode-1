class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        if (num.empty())
            return res;
        vector<bool> used;
        for (int i = 0; i < num.size(); i++)
        	used.push_back(false);
        vector<int> comb;
       	findPermute(0, num.size(), num, used, comb, res);
       	return res;
    }

    void findPermute(int curr, int size, vector<int> num, vector<bool> &used, vector<int> &comb, vector<vector<int> > &res) {
    	if (curr == size) {
    		res.push_back(comb);
    	} else {
    		for (int j = 0; j < size; j++)
    			if (!used[j]) {
    				comb.push_back(num[j]);
    				used[j] = true;
    				findPermute(curr+1, size, num, used, comb, res);
    				comb.pop_back();
    				used[j] = false;
    			}
    	}

    }