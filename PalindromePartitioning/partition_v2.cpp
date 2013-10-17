class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if (s.empty())
        	return res;
        vector<string> oneRes;
        findPalindrome(0, s, oneRes, res);
        return res;
    }

    void findPalindrome(string::size_type posi, string s, vector<string> &oneRes, vector<vector<string> > &res) {
    	if (posi == s.length()) {
    		res.push_back(oneRes);
    		return;
    	}
    	string::size_type posj = posi;
    	while (posj < s.length()) {
    		if (isPalindrome(s, posi, posj)) {
    			oneRes.push_back(s.substr(posi, posj-posi+1));
    			findPalindrome(posj+1, s, oneRes, res);
    			oneRes.pop_back();
    		}
    		posj++;
    	}
    }

    bool isPalindrome(string s, string::size_type posi, string::size_type posj) {
    	while (posi < posj) {
    		if (s[posi] != s[posj])
    			return false;
    		posi++; posj--;
    	}
    	return true;
    }
};