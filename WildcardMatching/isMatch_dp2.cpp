class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL)
            return true;
        if (s == NULL || p == NULL)
        	return false;
        int p_len = 0;
        for (int i = 0; i < strlen(p); i++) {
            if (p[i] != '*')
                p_len++;
        }
        if (strlen(s) < p_len)
            return false;
        vector<vector<bool> > opt(2, vector<bool>(strlen(s), false));
        int i = 0;
        opt[0][0] = true;
        bool flag = 1;
        while (i < strlen(p)) {
        	if (p[i] == '*') {
        		while (i+1 < strlen(p) && p[i+1] =='*')
        			i++;
                opt[flag][0] = opt[!flag][0];
        		int j = 0;
        		while (j < strlen(s)) {
        			if (opt[!flag][j+1] || opt[flag][j])
        				break;
        			else
        				opt[flag][j+1] = false;
        			j++;
        		}
        		while (j < strlen(s)) {
        			opt[flag][j+1] = true;
                    j++;
        		}
        	} else {
        		int j = 0;
        		while (j < strlen(s)) {
        			bool res = false;
        			if (s[j] == p[i] || p[i] == '?')
        				res = opt[!flag][j];
        			opt[flag][j+1] = res;
        			j++;
        		}
        		opt[flag][0] = false;
        	}
        	i++;
        	flag = !flag;
        }
        return opt[!flag][strlen(s)];
    }
};