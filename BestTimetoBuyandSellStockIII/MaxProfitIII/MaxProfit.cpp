#include "MaxProfit.h"
#include <iostream>

MaxProfit::MaxProfit(void)
{
}

int MaxProfit::maxProfit(vector<int> &prices) {
	if (prices.size() < 2)
		return 0;
	vector<int> pre;
	pre.push_back(0);
	int begin  = prices[0];
	int maxPro = 0;
	for (vector<int>::iterator iter = prices.begin() + 1; iter != prices.end(); iter++) {
		if (begin > *iter)
			begin = *iter;
		else 
			if (*iter - begin > maxPro) {
				maxPro = *iter - begin;
			}
		pre.push_back(maxPro);
	}
	int result = maxPro;
	vector<int> back;
	back.push_back(0);
	int end = *(prices.end()-1);
	maxPro = 0;
	for (int i = prices.size() - 2; i >= 0; i--) {
		if (end < prices[i])
			end = prices[i];
		else
			if (end - prices[i] > maxPro) {
				maxPro = end - prices[i];
			}
		back.insert(back.begin(), maxPro);
	}
	for (int i = 0; i < prices.size()-1; i++) {
		if (pre[i] + back[i+1] > result)
			result = pre[i] + back[i+1];
	}
	return result;
}

MaxProfit::~MaxProfit(void)
{
}
