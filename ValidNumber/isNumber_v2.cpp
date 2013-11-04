class Solution {
public:
    bool isNumber(const char *s) {
        if (*s == '\0')
            return false;
        while (*s != '\0' && isspace(*s))
            s++;
        if (*s == '\0')
            return false;
        const char *e = s + strlen(s) - 1;
        while (s < e && isspace(*e))
            e--;
        if (*s == '+' || *s == '-')
            s++;
        bool esign = false;
        bool num   = false;
        bool dot   = false;
        while (s <= e) {
            if (*s >= '0' && *s <= '9') {
                num = true;
            } else if (*s == '.') {
                if (esign || dot)
                    return false;
                dot = true;
            } else if (*s == 'e') {
                if (esign || !num)
                    return false;
                esign = true;
                num   = false;
            } else if (*s == '+' || *s == '-') {
                if (*(s-1) != 'e')
                    return false;
            } else
                return false;
            s++;
        }
        return num;
    }
};