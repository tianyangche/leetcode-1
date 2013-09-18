#include "FourSum.h"

int main() {
	FourSum foursum;
	vector<int> num;
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	/*
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(8);
	*/
	vector<vector<int> > result = foursum.fourSum(num, 0);
	for (vector<vector<int> >::iterator i = result.begin(); i != result.end(); i++) {
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
			cout << *j << " ";
		}
		cout << endl;
	}
	system("pause");
}