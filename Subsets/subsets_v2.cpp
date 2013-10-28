class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> subset;
        sort(S.begin(), S.end());
        dfs(0, S, subset, res);
        return res;
    }

    void dfs(int pos, vector<int> &s, vector<int> &subset, vector<vector<int> > &res) {
    	if (pos == s.size()) {
    		res.push_back(subset);
    		return;
    	}
    	subset.push_back(s[pos]);
    	dfs(pos+1, s, subset, res);
    	subset.pop_back();
    	dfs(pos+1, s, subset, res);
    }
};