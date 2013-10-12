class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL)
            return NULL;
        int lenh = strlen(haystack);
        int lenn = strlen(needle);
        if (lenh < lenn)
            return NULL;
        if (lenn == 0)
            return haystack;
        int i = 0;
        while (*haystack != '\0' && i + lenn <= lenh) {
        	if (*haystack == *needle) {
        		char * posi = haystack;
        		char * posj = needle;
        		bool flag = true;
        		while (*posi != '\0' && *posj != '\0') {
        			if (*posi != *posj) {
        				flag = false;
        				break;
        			}
        			posi++; posj++;
        		}
        		if (flag && *posj == '\0')
        			return haystack;
            }
            haystack++;
            i++;
        }
        return NULL;
    }
};