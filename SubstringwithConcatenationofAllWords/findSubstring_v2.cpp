class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty())
        	return res;
        unordered_map<string, int> matcher;
        for (vector<string>::iterator iter = L.begin(); iter != L.end(); iter++) {
        	matcher[*iter]++;
        }
        int n = L.size();
        int m = L[0].size();
        for (string::size_type i = 0; i < S.length() - n*m + 1; i++) {
        	unordered_map<string, int> matchee;
        	int j = 0;
        	while (j < n) {
        		string substring = S.substr(i+m*j, m);
        		if (matcher.count(substring) == 0)
        			break;
        		matchee[substring]++;
        		if (matchee[substring] > matcher[substring])
        			break;
        		j++;
        	}
        	if (j == n) {
        		res.push_back(i);
        	}
        }
        return res;
    }
};