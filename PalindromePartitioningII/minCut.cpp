class Solution {
public:
    int minCut(string s) {
        if (s.empty())
            return 0;
        int len = s.length();
        if (isPalindrome(s, 0, len-1))
            return 0;
        bool opt[len];
        memset(opt, 0, sizeof(bool)*len);
        opt[0] = true;
        for (int i = 1; i < len; i++)
        	if (isPalindrome(s, 0, i))
        		opt[i] = true;
        bool rec[len][len];
        for (int l = 1; l <= len; l++) {
        	for (int i = 0; i < len-l+1; i++) {
        		int j = i + l - 1;
        		if ( i == j)
        			rec[i][j] = true;
        		else {
        			if (s[i] != s[j])
        				rec[i][j] = false;
        			else
        				if (i+1 <= j-1)
        					if (rec[i+1][j-1])
        						rec[i][j] = true;
        					else
        						rec[i][j] = false;
        				else
        					rec[i][j] = true;
        		}
        	}
        }
        int iter = 0;
        while (opt[len-1] == false) {
        	for (int i = len-1; i > 0; i--) {
        		for (int j = 0; j < i; j++) {
        			if (opt[j] && rec[j+1][i]) {
        				opt[i] = true;
        			}
        		}
        	}
        	iter++;
        }
        return iter;
    }
    
    bool isPalindrome(string s, int i , int j) {
        while (i < j) {
    		if (s[i] != s[j])
    			return false;
    		i++;
    		j--;
    	}
    	return true;
    }
};