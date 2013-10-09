class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
        	return NULL;
        string s = "1";
        while (n > 1) {
        	string newString;
        	int num = 1;
        	int i = 0;
        	while (i < s.length()) {
        		int j = i;
        		while (j < s.length() && s[j] == s[i])
        			j++;
        		newString += '0' + j - i;
        		newString += s[i];
        		i = j;
        	}
        	n--;
        	s = newString;
        }
        return s;
    }
};