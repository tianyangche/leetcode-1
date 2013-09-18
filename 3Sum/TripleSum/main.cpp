#include <iostream>
#include "TripleSum.h"

int main() {
	TripleSum triplesum;
	vector<int> num;
	
	num.push_back(-1);
	num.push_back(-6);
	num.push_back(-3);
	num.push_back(-7);
	num.push_back(-4);
	num.push_back(-4);
	num.push_back(0);
	num.push_back(3);
	num.push_back(-2);
	num.push_back(-10);
	num.push_back(-10);
	num.push_back(9);
	vector<vector<int> > result_v = triplesum.threeSum(num);
	for (int i = 0; i < result_v.size(); i++)
		//for (vector<int>::iterator iter = result_v[i].begin(); iter != result_v[i].end(); i++)
			cout << result_v[i][0] << " " << result_v[i][1] << " " << result_v[i][2] << endl;
	system("pause");
}
