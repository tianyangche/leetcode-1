class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty() || dict.empty())
        	return false;
        int len = s.length();
        vector<bool> opt(len+1, false);
        opt[0] = true;
        for (int i = 0; i < len; i++) {
        	for (int j = i; j >= 0; j--) {
        		if (opt[j]) {
        			string sub = subString(s, j, i);
        			if (dict.count(sub) > 0)
        				opt[i+1] = true;
        		}
        	}
        }
        return opt[len];
    }

    string subString(string s, int begin, int end) {
    	string res;
    	for (int i = begin; i <= end; i++)
    		res += s[i];
    	return res;
    }
};