class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        if (n < 1 && k < 1)
        	return res;
        string s;
        int frac = 1;
        for (int i = 0; i < n; i++) {
        	s += '1' + i;
        	frac *= i + 1;
        }
        k--;
        for (int i = 0; i < n; i++) {
        	frac /= n - i;
        	int j = k / frac;
        	res.push_back(s[j]);
        	s.erase(s.begin()+j);
        	k %= frac;
        }
        return res;
    }
};