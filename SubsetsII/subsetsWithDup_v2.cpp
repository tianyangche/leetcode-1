class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> subset;
        sort(S.begin(), S.end());
        dfs(0, S, subset, res);
        return res;
    }

    void dfs(int pos, vector<int> &S, vector<int> &subset, vector<vector<int> > &res) {
    	if (pos == S.size()) {
    		res.push_back(subset);
    		return;
    	}
    	int posi = pos + 1;
    	while (posi < S.size() && S[pos] == S[posi]) {
    		posi++;
    	}
    	for (int i = posi; i >= pos; i--) {
    		if (i != posi)
    			subset.push_back(S[pos]);
    		dfs(posi, S, subset, res);
    	}
    	for (int i = pos; i < posi; i++) {
    		subset.pop_back();
    	}
    }
};