class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (s.empty() || dict.empty())
        	return res;
        int size = s.length();
        vector<bool> opt(size+1, false);
        opt[0] = true;
        unordered_map<int, vector<int> > recs;
        for (int i = 0; i < size; i++) {
        	for (int j = i; j >= 0; j--) {
        		if (opt[j]) {
        			string substring = subString(s, j, i);
        			if (dict.count(substring) > 0) {
        				opt[i+1] = true;
        				recs[i].push_back(j-1);
        			}
        		}
        	}
        }
        if (!opt[size])
        	return res;
        buildPath(size-1, recs, "", res, s);
    	return res;
    }

    void buildPath(int pos, unordered_map<int, vector<int> > &recs, string oneCom, vector<string> &res, string s) {
    	if (pos == -1) {
    		res.push_back(oneCom);
    		return;
    	}
    	const vector<int> &prev = recs[pos];
    	for (vector<int>::const_iterator iter = prev.begin(); iter != prev.end(); iter++) {
    	    string next = subString(s, (*iter)+1, pos);
    	    if (!oneCom.empty())
    	        next += " " + oneCom;
    		buildPath(*iter, recs, next, res, s);
    	}
    }

    string subString(string s, int begin, int end) {
    	string res;
    	for (int i = begin; i <= end; i++)
    		res += s[i];
    	return res;
    }
};