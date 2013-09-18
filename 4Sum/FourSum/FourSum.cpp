#include "FourSum.h"
#include "Sum.h"

FourSum::FourSum(void)
{
}

vector<vector<int> > FourSum::fourSum(vector<int> &num, int target) {
	vector<Sum> doubleSum;
	vector<vector<int> > result;
	
	for (int i = 0; i < num.size(); i++) {
		for (int j = i + 1; j < num.size(); j++) {
			Sum sum = Sum(num[i]+num[j], i, j);
			doubleSum.push_back(sum);
		}
	}
	sort(doubleSum.begin(), doubleSum.end());
	for (vector<Sum>::iterator i = doubleSum.begin(); i != doubleSum.end(); i++) {
		vector<Sum>::iterator start = lower_bound(doubleSum.begin(), doubleSum.end(), Sum(target-(i->value)));
		if (start != doubleSum.end() && (start->value) + (i->value) == target) {
			vector<Sum>::iterator iter = start;
			while (iter != doubleSum.end() && (iter->value) == (start->value)) {
				if ((iter->x != i->x) && (iter->x != i->y) && (iter->y != i->x) && (iter->y != i->y)) {
					vector<int> elem;
					elem.push_back(num[iter->x]);
					elem.push_back(num[iter->y]);
					elem.push_back(num[i->x]);
					elem.push_back(num[i->y]);
					sort(elem.begin(), elem.end());
					if (find(result.begin(), result.end(), elem) == result.end())
						result.push_back(elem);
				}
				iter++;
			}
		}
	}
	return result;
}


FourSum::~FourSum(void)
{
}
