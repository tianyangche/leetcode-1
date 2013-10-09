class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        int n = s.length();
        vector<int> opt(n+1, 0);
        opt[0] = 1;
        if (s[0] != '0')
            opt[1] = 1;
        for (int i = 1; i < n; i++) {
        	if (convert(s, i-1, i))
        		opt[i+1] = opt[i-1];
        	if (s[i] != '0')
        		opt[i+1] += opt[i];
        }
    	return opt[n];
    }

    bool convert(const string &s, int posi, int posj) {
     	if (s[posi] == '0')
            return false;
        int num = 10*(s[posi] - '0') + s[posj] - '0';
     	if (num > 0 && num <= 26)
     		return true;
     	else
     		return false;
    }
};