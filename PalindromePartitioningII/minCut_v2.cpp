class Solution {
public:
    int minCut(string s) {
        if (s.empty())
        	return 0;
        vector<int> opt(s.length()+1, -1);
        opt[0] = 0;

        vector<vector<bool> > recs(s.length(), vector<bool>(s.length(), false));
        for (string::size_type len = 0; len < s.length(); len++) {
        	for (string::size_type i = 0; i < s.length()-len; i++) {
        		string::size_type j = i + len;
        		recs[i][j] = s[i] == s[j];
        		recs[i][j] = len > 1 ? recs[i][j] && recs[i+1][j-1] : recs[i][j];
        	}
        }

        for (string::size_type j = 0; j < s.length(); j++) {
        	for (string::size_type i = 0; i <= j; i++) {
        		if (opt[i] != -1 && recs[i][j]) {
        			if (i == 0)
        				opt[j+1] = opt[j+1] == -1 ? opt[i] : min(opt[j+1], opt[i]);
        			else
        				opt[j+1] = opt[j+1] == -1 ? opt[i] + 1 : min(opt[j+1], opt[i] + 1);
        		}
        	}
        }
        return opt[s.length()];
    }
};