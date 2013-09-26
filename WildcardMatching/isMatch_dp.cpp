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
        vector<vector<bool> > opt(2, vector<bool>(strlen(p), false));
        opt[0][0] = true;
        bool flag = true;
        for (int i = 0; i < strlen(p); i++) {
            if (flag && p[i] == '*')
                opt[0][i+1] = true;
            else {
                opt[0][i+1] = false;
                flag = false;
            }
        }
        flag = 1;
        for (int i = 1; i <= strlen(s); i++) {
            opt[flag][0] = false;
            for (int j = 1; j <= strlen(p); j++) {
                if (s[i-1] == p[j-1]) {
                    if (opt[!flag][j-1])
                        opt[flag][j] = true;
                    else
                        opt[flag][j] = false;
                } else if (p[j-1] == '*') {
                    if (opt[!flag][j] || opt[flag][j-1] || opt[!flag][j-1])
                        opt[flag][j] = true;
                    else
                        opt[flag][j] = false;
                } else if (p[j-1] == '?')
                    if (opt[!flag][j-1])
                        opt[flag][j] = true;
                    else
                        opt[flag][j] = false;
                else
                    opt[flag][j] = false;
            }
            flag = !flag;
        }
        return opt[!flag][strlen(p)];
    }
};