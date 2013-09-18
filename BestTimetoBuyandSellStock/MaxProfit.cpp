class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        int result = 0;
        int min    = prices[0];
        for (vector<int>::iterator i = prices.begin(); i != prices.end(); i++) {
            if (*i < min) {
                min = *i;
            } else {
              if (*i - min > result)
                result = *i - min;
            }
        }
        return result;
    }
};