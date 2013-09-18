class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if (strs.empty())
            return res;
        map<string, int> rec;
        for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++) {
            string prefix = "";
        	for (int i = 0; i < iter->length(); i++) {
        		prefix += (*iter)[i];
        		map<string, int>::iterator pos = rec.find(prefix);
        		if (pos == rec.end()) {
        			rec.insert(make_pair(prefix, 1));
        		} else {
        			pos->second++;
        		}
        	}
        }
        int maxLen = 0;
        for (map<string, int>::iterator iter = rec.begin(); iter != rec.end(); iter++) {
        	if (iter->second == strs.size() && (iter->first).length() > maxLen) {
        		maxLen = (iter->first).length();
        		res = iter->first;
        	}
        }
        if (maxLen == 0)
            return "";
        else 
            return res;
    }
};