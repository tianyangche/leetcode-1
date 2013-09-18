class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        if (S.empty())
            return res;
        sort(S.begin(), S.end());
        vector<bool> used;
        for (int i = 0; i < S.size(); i++)
            used.push_back(false);
        for (int len = 1; len <= S.size(); len++) {
        	for (int i = 0; i < S.size(); i++)
        		used[i] = false;
        	for (int i = 0; i < S.size(); i++) {
        		if (((i > 0 && S[i] != S[i-1]) || i == 0) && !used[i]) {
        			used[i] = true;
        			findSets(i, 1, len, used, S, res);
        			used[i] = false;
        		}
        	}
        }
        return res;
    }

    void findSets(int pos, int ith, int len, vector<bool> &used, vector<int> &s, vector<vector<int>> &res) {
    	if (ith == len) {
    		vector<int> temp;
    		for (int i = 0; i < s.size(); i++)
    			if (used[i])
    				temp.push_back(s[i]);
    		res.push_back(temp);
    	} else {
    		for (int i = pos+1; i < s.size(); i++) {
    			if (((i > pos+1 && s[i] != s[i-1]) || i == pos+1) && !used[i]) {
    				used[i] = true;
    				findSets(i, ith+1, len, used, s, res);
    				used[i] = false;
    			}
    		}
    	}
    }
};