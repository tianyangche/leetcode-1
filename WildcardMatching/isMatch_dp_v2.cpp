class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        
        if (*s == '\0' && *p == '\0')
            return true;
        
        size_t slen  = strlen(s);
        size_t plen  = strlen(p);
        size_t p_len = 0;
        
        for (size_t i = 0; i < plen; i++) {
            if (p[i] != '*')
                p_len++;
        }
        if (strlen(s) < p_len)
            return false;
        
        vector<vector<bool> > opt = vector<vector<bool> >(2, vector<bool>(plen+1, false));
        opt[0][0] = true;
        
        for (size_t i = 0; i < plen; i++) {
            if (p[i] != '*')
                break;
            opt[0][i+1] = true;
        }
        
        bool flag = true;
        for (size_t i = 1; i <= slen; i++) {
            opt[flag][0] = false;
            for (size_t j = 1; j <= plen; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                    opt[flag][j] = opt[!flag][j-1];
                } else if (p[j-1] == '*') {
                    opt[flag][j] = opt[flag][j-1] || opt[!flag][j-1] || opt[!flag][j];
                } else {
                    opt[flag][j] = false;
                }
            }
            flag = !flag;
        }
        
        return opt[!flag][plen];
    }
};