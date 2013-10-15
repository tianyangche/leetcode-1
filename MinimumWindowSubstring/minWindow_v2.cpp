class Solution {
public:
    string minWindow(string S, string T) {
        if (S.empty() || T.empty())
        	return "";
        unordered_map<char, int> freqT;
        for (string::iterator iter = T.begin(); iter != T.end(); iter++) {
        	freqT[*iter]++;
        }
        string::iterator i = S.begin();
        string::iterator j = S.begin();
        string::size_type matched = 0;
        int minLen  = INT_MAX;
        string::iterator begin, end;
        unordered_map<char, int> recs;
        while (j != S.end()) {
        	if (recs[*j] < freqT[*j])
        		matched++;
        	recs[*j]++;
        	if (matched == T.length()) {
        		while (i < j) {
        			if (recs[*i] > freqT[*i]) {
        				recs[*i]--;
        				i++;
        			} else
        				break;
        		}
        		if (minLen > j-i+1) {
        			minLen = j - i + 1;
        			begin = i; end = j;
        		}
        	}
        	j++;
        }
        return matched == T.length() ? string(begin, end+1) : "";
    }
};