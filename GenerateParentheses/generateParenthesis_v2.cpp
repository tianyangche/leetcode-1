class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n < 1)
        	return res;
        string word;
        generate(0, 0, n, word, res);
        return res;
    }

    void generate(int left, int right, int n, string &word, vector<string> &res) {
    	if (left == n && right == n) {
    		res.push_back(word);
    		return;
    	}
    	if (left < n) {
    		for (int i = left + 1; i <= n; i++) {
    			word += '(';
    			generate(i, right, n, word, res);
    			word.pop_back();
    		}
    	}
    	if (right < left) {
    		for (int i = right + 1; i <= right; i++) {
    			word += ')';
				generate(left, i, n, word, res);
				word.pop_back();
    		}
    	}
    }
};