#include "TripleSum.h"
#include <iostream>

TripleSum::TripleSum(void)
{
}

vector<vector<int> > TripleSum::threeSum(vector<int> &num) {
	
	sort(num.begin(), num.end());
	int n = num.size();
	vector<int> item;
	vector<vector<int> > result;
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			int sum = num[i] + num[j] + num[k];
			if (sum < 0)
				j++;
			else
				if (sum > 0)
					k--;
				else
					if (sum == 0) {
						item.push_back(num[i]);
						item.push_back(num[j]);
						item.push_back(num[k]);
						if (find(result.begin(), result.end(), item) == result.end())
							result.push_back(item);
						item.clear();
						j++;
						k--;
					}
		}
	}
	return result;
}

TripleSum::~TripleSum(void)
{
}
