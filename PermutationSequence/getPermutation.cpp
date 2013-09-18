class Solution {
public:
    string getPermutation(int n, int k) {
       string st;
       string res;
       if (n <= 0 || k <= 0)
           	return res;
       	int fac = 1;
       	for (int i = 0; i < n; i++) {
       		st.push_back('1' + i);
       		fac *= (i + 1);
       	}
       	k--;
       	for (int i = 0; i < n; i++) {
       		fac /= (n - i);
       		int pos = k / fac;
       		res.push_back(st[pos]);
       		st.erase(st.begin() + pos);
       		k = k % fac;
       	}
       	return res;
    }
};