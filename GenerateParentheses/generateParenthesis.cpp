class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0)
        	return result;
        string s;
        generate(result, s, 0, 0, n);
        return result;
    }

    void generate(vector<string> & result, string s, int pre, int pos, int n) {
    	if (pos == 2*n - 1) {
    		s.push_back(')');
			result.push_back(s);
    	} else {
    		if (pre < n) {
    			s.push_back('(');
    			generate(result, s, pre+1, pos+1, n);
    			s.pop_back();
    		}
    		if (pos - pre < pre) {
    			s.push_back(')');
				generate(result, s, pre, pos+1, n);
				s.pop_back();
    		}
    	}
    }
};