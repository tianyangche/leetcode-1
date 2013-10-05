class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
        	return 0;
        int res = 0;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
        	if (prices[i] < minimum) {
        		minimum = prices[i];
        		maximum = prices[i];
        	} else if (minimum != INT_MAX && prices[i] > maximum) {
        		maximum = prices[i];
        		res = max(res, maximum - minimum);
        	}
        }
        return res;
    }
};