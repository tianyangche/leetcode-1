class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.empty())
        	return prefix;
        unordered_map<string, int> recs;
        for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++) {
        	string prev;
        	for (string::size_type i = 0; i <(*iter).length(); i++) {
        		prev += (*iter)[i];
        		recs[prev]++;
        	}
        }
        for (unordered_map<string, int>::iterator iter = recs.begin(); iter != recs.end(); iter++) {
        	if (iter->second == strs.size() && (iter->first).length() > prefix.length()) {
        		prefix = iter->first;
        	}
        }
        return prefix;
    }
};