class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1)
        	return s;
        string palidrome;
        int maxLen = 0;
        for (string::size_type i = 0; i < s.length(); i++) {
        	string temp;
        	int len = checkPalindrome(s, i-1, i, temp);
        	if (len > maxLen) {
        		palidrome = temp;
        		maxLen = len;
        	}
        	len = checkPalindrome(s, i, i+1, temp);
        	if (len > maxLen) {
        		palidrome = temp;
        		maxLen = len;
        	}
        	len = checkPalindrome(s, i-1, i+1, temp) + 1;
        	temp = len == 1 ? string(1, s[i]) : temp;
        	if (len > maxLen) {
        		palidrome = temp;
        		maxLen = len;
        	}
        }
        return palidrome;
    }

    int checkPalindrome(string s, string::size_type i, string::size_type j, string &temp) {
    	int len = 0;
    	while (i >= 0 && j < s.length()) {
    		if (s[i] != s[j])
    			break;
    		len++;
    		i--; j++;
    	}
    	temp = len > 0 ? string(s, i+1, j-i-1) : "";
    	return 2*len;
    }
};