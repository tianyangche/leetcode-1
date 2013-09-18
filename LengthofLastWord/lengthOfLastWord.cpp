class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int n = 0;
        while (s[len-1] == ' ' && len > 0)
            len--;
        while (s[len-1] != ' ' && len > 0) {
        	len--;
        	n++;
        }
        return n;
    }
};