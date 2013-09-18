class Solution {
public:
    string convert(string s, int nRows) {
        string res;
        if (s.empty())
        	return res;
        if (nRows <= 1)
        	return s;
        int zigzag_size = 2 * nRows - 2;
        for (int i = 0; i < nRows; i++) {
        	for (int j = i; j < s.size(); j += zigzag_size) {
        		res += s[j];
        		if (i > 0 && i < nRows-1) {
        			int k = j + zigzag_size - 2*i;
        			if (k < s.size())
        				res += s[k];
        		}
        	}
        }
        return res;
    }
};