#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class FourSum
{
public:
	FourSum(void);
	vector<vector<int> > fourSum(vector<int> &num, int target);
	~FourSum(void);
};

