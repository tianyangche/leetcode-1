class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        bool flag = false;
        while (*s != '\0') {
        	if (*s == ' ') {
        		flag = false;
        	} else {
        		if (!flag) {
        			len = 1;
        			flag = true;
        		} else
        			len++;
        	}
        	s++;
        }
        return len;
    }
};