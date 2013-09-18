#include "MaxProfit.h"


MaxProfit::MaxProfit(void)
{
}

int maxProfit(vector<int> &prices) {
	if (prices.size() < 2)
		return 0;
	bool flag = false;
	int begin = prices[0];
	int end   = 0;
	int sum	  = 0;
	for (vector<int>::iterator i = prices.begin() + 1; i != prices.end(); i++) {
		if (flag) {
			if (end < *i)
				end = *i;
			else {
				sum  += end - begin;
				begin = *i;
				end   = 0;
				flag  = false;
			}
		} else {
			if (begin > *i)
				begin = *i;
			else {
				end = *i;
				flag = true;
			}
		}
	}
	if (flag && (end - begin > 0))
		sum += end - begin;
	return sum;
}

MaxProfit::~MaxProfit(void)
{
}
