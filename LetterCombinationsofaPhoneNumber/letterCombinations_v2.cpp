class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
        	res.push_back("");
        	return res;
        }
        unordered_map<int, vector<char> > recs;
        buildMap(recs);
        genCombine(digits, 0, "", recs, res);
        return res;
    }

    void genCombine(string &digits, int pos, string oneCombine, unordered_map<int, vector<char> > &recs, vector<string> &res) {
    	if (pos == digits.length()) {
    		res.push_back(oneCombine);
    		return;
    	}
    	int key = digits[pos] - '0';
    	if (key < 0 || key > 9 || key == 1)
    		return;
    	const vector<char> &represent = recs[key];
    	for (int i = 0; i < represent.size(); i++) {
    		genCombine(digits, pos+1, oneCombine+represent[i], recs, res);
    	}
    }

    void buildMap(unordered_map<int, vector<char> > &recs) {
    	char ch = 'a';
    	for (int i = 2; i <= 9; i++) {
    		int len = i!=7 && i!=9 ? 3 : 4;
    		int k = 0;
    		while (k < len) {
    			recs[i].push_back(ch);
    			k++;
    			ch++;
    		}
    	}
    	recs[0].push_back(' ');
    }
};