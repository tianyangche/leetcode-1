class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0' && *p == '\0')
            return true;
        if (*s == '\0') {
            const char *pp = p;
            while (*pp == '*')
                pp++;
            return *pp == '\0' ? true : false;
        }
        if (*p == '\0')
            return false;
        if (*s == *p)
            return isMatch(s+1, p+1);
        if (*p == '*') {
            const char *pp = p;
            while (*(pp+1) == '*')
                pp++;
            if (isMatch(s, pp+1))
                return true;
            if (isMatch(s+1, pp+1))
                return true;
            if (isMatch(s+1, pp))
                return true;
        } else if (*p == '?') {
            return isMatch(s+1, p+1);
        }
        return false;
    }
};