class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        if (words.empty())
            return res;
        int i = 1;
        int lenOfWords = words[0].length();
        int lenOfSpace = 0;
        int start = 0;
        while (i < words.size()) {
            if (lenOfWords + lenOfSpace + words[i].length() + 1 <= L) {
                lenOfWords += words[i].length();
        		lenOfSpace++;
        	} else {
        		int spaces = 0;
        		int r = 0;
        		string temp;
            	if (i - 1 - start > 0) {
        			spaces = (L - lenOfWords) / (i - 1 - start);
        		    r = (L - lenOfWords) % (i - 1 - start);
            	}
                for (int k = start; k < i; k++) {
            	    temp += words[k];
        		    if (k + 1 < i) {
                        for (int m = 0; m < spaces; m++)
        		    	    temp += " ";
        		        if (r > 0) {
        		    	    temp += " ";
                            r--;
        		        }
        		    }
        		}
                int tlen = temp.length();
                if (tlen < L)
                    for (int k = 0; k < L - tlen; k++)
                        temp += " ";
        		res.push_back(temp);
        		start = i;
        		lenOfWords = words[i].length();
        		lenOfSpace = 0;
        	}
        	i++;
        }
        string temp;
        for (int k = start; k < words.size(); k++) {
           	temp += words[k];
            if (k + 1 < words.size())
              	temp += " ";
            else {
              	int tLen = temp.length();
            	for (int m = 0; m < L - tLen; m++)
        			temp += " ";
            }
        }
        res.push_back(temp);
        return res;
    }
};