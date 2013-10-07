class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        if (n < 1 || k < 1)
            return res;
        vector<bool> used(n+1, false);
        vector<int> oneCombine;
        findCombine(used, 0, 1, n, k, oneCombine, res);
        return res;
    }

    void findCombine(vector<bool> &used, int pos, int curr, int n, int k, vector<int> &oneCombine, vector<vector<int> > &res) {
    	if (pos == k) {
    		res.push_back(oneCombine);
    		return;
    	}
    	for (int i = curr; i <= n; i++) {
    		if (!used[i]) {
    			oneCombine.push_back(i);
                used[i] = true;
    			findCombine(used, pos+1, i+1, n, k, oneCombine, res);
    			oneCombine.pop_back();
                used[i] = false;
    		}
    	}
    }
};