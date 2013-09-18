class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        string res;
        for (int k = 0; k < s.length(); k++) {
        	int i = k-1;
        	int j = k+1;
        	findPalindrome(s, i, j);
        	if (res.length() < j - i + 1) {
        		res = subString(s, i, j);
        	}
        	if (k - 1 >= 0 && s[k-1] == s[k]) {
        		i = k - 2;
        		j = k + 1;
        		findPalindrome(s, i, j);
        		if (res.length() < j - i + 1) {
        			res = subString(s, i, j);
        		}
        	}
        	if (k + 1 < s.length() && s[k+1] == s[k]) {
        		i = k - 1;
        		j = k + 2;
        		findPalindrome(s, i, j);
        		if (res.length() < j - i + 1) {
        			res = subString(s, i, j);
        		}
        	}
        }
        return res;
    }

    void findPalindrome(string s, int &i, int &j) {
    	
    	while (i >= 0 && j < s.length() && s[i] == s[j]) {
        	i--;
        	j++;
        }
        i++;
        j--;
    }

    string subString(string s, int i, int j) {
    	string res;
    	for (int k = i; k <= j; k++) {
    		res += s[k];
    	}
    	return res;
    }
};