class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows < 1)
        	return "";
        if (nRows == 1)
        	return s;
       	string res;
       	for (int i = 0; i < nRows; i++) {
       		for (int j = i; j < s.length(); j += 2*nRows-2) {
       			res += s[j];
       			if (i != 0 && i + 1 != nRows) {
       				int k = j + 2 * (nRows - i - 1);
       				if (k < s.length()) {
       					res += s[k];
       				}
       			}
       		}
       	}
       	return res;
    }
};