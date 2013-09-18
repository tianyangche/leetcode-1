class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            string tmp;
            res.push_back(tmp);
            return res;
        }
        getCom(res, digits, 0, "");
        
    }

    void getCom(vector<string> &res, string digits, int pos, string tmp) {
    	if (pos == digits.size()) {
    		res.push_back(tmp);
    	} else {
    		if (digits[pos] == '2') {
    			getCom(res, digits, pos+1, tmp+'a');
    			getCom(res, digits, pos+1, tmp+'b');
    			getCom(res, digits, pos+1, tmp+'c');
    		} else if (digits[pos] == '3') {
    			getCom(res, digits, pos+1, tmp+'d');
    			getCom(res, digits, pos+1, tmp+'e');
    			getCom(res, digits, pos+1, tmp+'f');
    		} else if (digits[pos] == '4') {
    			getCom(res, digits, pos+1, tmp+'g');
    			getCom(res, digits, pos+1, tmp+'h');
    			getCom(res, digits, pos+1, tmp+'i');
    		} else if (digits[pos] == '5') {
    			getCom(res, digits, pos+1, tmp+'j');
    			getCom(res, digits, pos+1, tmp+'k');
    			getCom(res, digits, pos+1, tmp+'l');
    		} else if (digits[pos] == '6') {
    			getCom(res, digits, pos+1, tmp+'m');
    			getCom(res, digits, pos+1, tmp+'n');
    			getCom(res, digits, pos+1, tmp+'o');
    		} else if (digits[pos] == '7') {
    			getCom(res, digits, pos+1, tmp+'p');
    			getCom(res, digits, pos+1, tmp+'q');
    			getCom(res, digits, pos+1, tmp+'r');
    			getCom(res, digits, pos+1, tmp+'s');
    		} else if (digits[pos] == '8') {
    			getCom(res, digits, pos+1, tmp+'t');
    			getCom(res, digits, pos+1, tmp+'u');
    			getCom(res, digits, pos+1, tmp+'v');
    		} else if (digits[pos] == '9') {
    			getCom(res, digits, pos+1, tmp+'w');
    			getCom(res, digits, pos+1, tmp+'x');
    			getCom(res, digits, pos+1, tmp+'y');
    			getCom(res, digits, pos+1, tmp+'z');
    		}
    	}
    }
};