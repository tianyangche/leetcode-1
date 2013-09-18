#include <iostream>
#include "MaxProfit.h"

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	MaxProfit maxProfit;
	cout << maxProfit.maxProfit(a) << endl;
	system("pause");
}