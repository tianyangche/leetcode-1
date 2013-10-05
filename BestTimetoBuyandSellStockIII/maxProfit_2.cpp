class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int order[n];
        int inorder[n];
        memset(order  , 0, sizeof(int)*n);
        memset(inorder, 0, sizeof(int)*n);
        int minimum = prices[0];
        int diff = 0;
        for (int i = 1; i < n; i++) {
        	minimum  = min(minimum, prices[i]);
        	diff 	 = max(diff, prices[i] - minimum);
        	order[i] = diff;
        }
        int maximum = prices[n-1];
        diff = 0;
        for (int i = n - 2; i >= 0; i--) {
        	maximum    = max(maximum, prices[i]);
        	diff	   = max(diff, maximum - prices[i]);
        	inorder[i] = diff;
        }
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
        	res = max(res, order[i] + inorder[i+1]);
        }
        res = max(res, order[n-1]);
        return res;
    }
};