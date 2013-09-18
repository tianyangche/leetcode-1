class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        const int hlen = strlen(haystack);
        const int nlen = strlen(needle);
        if (hlen < nlen)
            return NULL;
        if (nlen == 0)
            return haystack;
        for (int i = 0; i < hlen - nlen + 1; i++) {
        	if (haystack[i] == needle[0]) {
                int ii = i;
        		int j  = 0;
        		while (haystack[ii] == needle[j] && ii < hlen && j < nlen) {
        			ii++;
                    j++;
        		}
        		if (j == nlen) {
        			return haystack+i;
        		}
        	}
        }
        return NULL;
    }
};