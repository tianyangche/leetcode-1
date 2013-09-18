class Solution {
public:
    string minWindow(string S, string T) {
        if (S.length() == 0 || T.length() == 0)
            return "";
        int used[256];
        memset(used, 0, sizeof(used));
        int len = 0;
        for (int i = 0; i < T.length(); i++) {
            used[T[i]-'A']++;
            len++;
        }
        int i = 0, j = 0;
        int minlen = INT_MAX;
        int leni = 0;
        int start = 0, end = 0;
        int aused[256];
        memset(aused, 0, sizeof(aused));
        while (j < S.length()) {
        	if (used[S[j]-'A'] > 0) {
        		if (aused[S[j]-'A'] < used[S[j]-'A'])
        			leni++;
        		aused[S[j]-'A']++;
        	}
            j++;
        	if (leni == len) {
        		while (i < S.length()) {
        			if (used[S[i]-'A'] > 0) {
        				if (aused[S[i]-'A'] > used[S[i]-'A'])
        					aused[S[i]-'A']--;
        				else
        					break;
        			}
        			i++;
        		}
        		if (j - i < minlen) {
        			start = i;
        			end = j;
        			minlen = j - i;
        		}
        	}
        }
		string result;
		for (int i = start; i < end; i++)
			result.push_back(S[i]);
		return result;
    }
};