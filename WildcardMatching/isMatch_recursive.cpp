class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL)
            return true;
        if (s == NULL || p == NULL)
            return false;
        return isMatch(s, p, 0, 0);
    }

    bool isMatch(const char *s, const char *p, int i, int j) {
    	if (i == strlen(s) && j == strlen(p))
    		return true;
    	if (i == strlen(s)) {
    		for (int k = j; k < strlen(p); k++)
    			if (p[k] != '*')
    				return false;
    		return true;
    	}
    	if (j == strlen(p))
    		return false;
    	bool res = false;
    	if (s[i] == p[j])
    		res = isMatch(s, p, i+1, j+1);
    	if (res)
    		return true;
    	if (p[j] == '*') {
            int k = j;
            while (k+1 < strlen(p) && p[k+1] == '*')
            	k++;
    		res = isMatch(s, p, i, k+1);
    		if (res)
    			return true;
    		res = isMatch(s, p, i+1, k);
    		if (res)
    			return true;
    		res = isMatch(s, p, i+1, k+1);
    		if (res)
    			return true;
    	}
    	if (p[j] == '?')
    		res = isMatch(s, p, i+1, j+1);
    	if (res)
    		return true;
    	else
    		return false;
    }
};