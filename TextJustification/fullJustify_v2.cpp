class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        if (words.empty())
        	return res;
        int i = 0;
        while (i < words.size()) {
        	int j = i + 1;
        	int len = words[i].length();
        	string word;
        	while (j < words.size() && len + words[j].length() + 1 <= L) {
        		len += words[j].length() + 1;
        		j++;
        	}
        	j--;
        	if (j == i) {
        		word = words[j];
        		int tlen = word.length();
        		for (string::size_type s = 0; s < L - tlen; s++) {
        			word += " ";
        		}
        		res.push_back(word);
        		i = j + 1;
        		continue;
        	}
        	int nspace = L - len;
        	if (j + 1 != words.size()) {
        		int nspaceperword = nspace / (j - i);
        		int nspacemod	  = nspace % (j - i);
        		for (int k = i; k <= j; k++) {
        			word += words[k];
        			if (k != j) {
        				for (int m = 0; m <= nspaceperword; m++) {
        					word += " ";
        				}
        				if (nspacemod > 0) {
        					word += " ";
        					nspacemod--;
        				}
        			}
        		}
        	} else {
        		for (int k = i; k < j; k++) {
        			word += words[k] + " ";
        		}
        		word += words[j];
        		for (int k = 0; k < nspace; k++) {
        			word += " ";
        		}
        	}        	
        	res.push_back(word);
        	i = j + 1;
        }
        return res;
    }
};