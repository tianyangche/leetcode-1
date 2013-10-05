class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.empty())
            return res;
        map<string, vector<string> > anagrams;
        for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++) {
        	string tempStr = *iter;
        	sort(tempStr.begin(), tempStr.end());
        	anagrams[tempStr].push_back(*iter);
        }
        for (map<string, vector<string> >::iterator iter = anagrams.begin(); iter != anagrams.end(); iter++) {
        	if ((iter->second).size() > 1) {
        		res.insert(res.end(), (iter->second).begin(), (iter->second).end());
        	}
        }
        return res;
    }
};