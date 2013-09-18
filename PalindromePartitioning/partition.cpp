class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty())
            return res;
        vector<string> curr;
        int len = s.length();
        findPalindrome(s, 0, len, curr, res);
        return res;
    }

    void findPalindrome(string s, int posi, int posj, vector<string> &curr, vector<vector<string>> &res) {
        if (posi == posj) {
    		res.push_back(curr);
    	} else {
    		int i = posi;
    		while (i < posj) {
    			if (isPalindrome(s, posi, i)) {
    				curr.push_back(s.substr(posi, i-posi+1));
    				findPalindrome(s, i+1, posj, curr, res);
    				curr.pop_back();
    			}
    			i++;
    		}
    	}
    }

    bool isPalindrome(string s, int i, int j) {
    	while (i < j) {
    		if (s[i] != s[j])
    			return false;
    		i++;
    		j--;
    	}
    	return true;
    }
};