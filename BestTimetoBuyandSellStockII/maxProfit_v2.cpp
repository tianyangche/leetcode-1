class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        int res = 0;
        int minimum = prices[0];
        int diff = 0;
        for (int i = 1; i < prices.size(); i++) {
        	if (prices[i] < prices[i-1]) {
        		res += diff;
        		minimum = prices[i];
        		diff = 0;
        	} else {
        		diff = prices[i] - minimum;
        	}
        }
        if (diff != 0)
        	res += diff;
        return res;
    }
};