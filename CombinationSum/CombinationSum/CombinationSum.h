#pragma once
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class CombinationSum
{
public:
	CombinationSum(void);
	vector<vector<int> > combinationSum(vector<int> &candidates, int target);
	void newPath(map<int, vector<vector<int> > > &paths, int i, int j);
	~CombinationSum(void);
};

