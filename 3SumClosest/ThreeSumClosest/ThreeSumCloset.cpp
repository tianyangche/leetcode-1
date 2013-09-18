#include "ThreeSumCloset.h"


ThreeSumCloset::ThreeSumCloset(void)
{
}

int ThreeSumCloset::threeSumClosest(vector<int> &num, int target) {

	int result = 10000;
	sort(num.begin(), num.end());
	for (vector<int>::iterator i = num.begin(); i != num.end() - 2; i++) {
		vector<int>::iterator j = i + 1;
		vector<int>::iterator k = num.end() - 1;
		while (j < k) {
			int sum = *i + *j + *k;
			if (abs(sum-target) < abs(result-target))
				result = sum;
			if (sum > target)
				k--;
			else
				if (sum < target)
					j++;
			else {
				return result;
			}
		}
	}
	return result;
}

ThreeSumCloset::~ThreeSumCloset(void)
{
}
