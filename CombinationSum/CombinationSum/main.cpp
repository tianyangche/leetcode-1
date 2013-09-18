#include <iostream>
#include "CombinationSum.h"

int main() {
	vector<int> x;
	x.push_back(8);
	x.push_back(7);
	x.push_back(4);
	x.push_back(3);
	//x.push_back(2);
	int target = 11;
	CombinationSum combinationSum;
	vector<vector<int> > result = combinationSum.combinationSum(x, target);
	for (vector<vector<int> >::iterator i = result.begin(); i != result.end(); i++) {
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
			cout << *j << " ";
		}
		cout << endl;
	}
	system("pause");
}