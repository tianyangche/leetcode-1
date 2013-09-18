class Solution {
public:
    int numTrees(int n) {
        if (n == 0)
        	return 1;
        if (n == 1)
        	return 1;
        vector<int> opt;
        opt.push_back(1);
        opt.push_back(1);
        for (int i = 2; i <= n; i++) {
        	int k = 0;
        	for (int j = 0; j < i; j++) {
        		k += opt[j] * opt[i-j-1];
        	}
        	opt.push_back(k);
        }
        return opt[n];
    }
};