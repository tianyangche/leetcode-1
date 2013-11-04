class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
        	return true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
        	while (i < s.length() && !((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || (s[i] >= '0' && s[i] <= '9')))
        		i++;
        	while (j >= 0 && !((tolower(s[j]) >= 'a' && tolower(s[j]) <= 'z') || (s[j] >= '0' && s[j] <= '9')))
        		j--;
        	if (i > j)
        	    return true;
        	if (s[i] >= '0' && s[i] <= '9') {
        		if (s[i] != s[j])
        			return false;
        	} else if (tolower(s[i]) != tolower(s[j]))
        		return false;
        	i++;
        	j--;
        }
        return true;
    }
};