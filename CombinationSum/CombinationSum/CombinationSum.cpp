#include "CombinationSum.h"
#include <iostream>

CombinationSum::CombinationSum(void)
{
}

vector<vector<int> > CombinationSum::combinationSum(vector<int> &candidates, int target) {
	
	bool used[1000];
	map<int, vector<vector<int> > > paths;
	vector<vector<int> > result;

	memset(used, 0, sizeof(used));
	used[0] = true;
	sort(candidates.begin(), candidates.end());
	for (vector<int>::iterator i = candidates.begin(); i != candidates.end(); i++) {
		for (int j = 0; j < 1000; j++) {
			if (!used[j])
				continue;
			if (j + *i > target)
				break;
			newPath(paths, j, *i);
			used[*i+j] = true;
		}
	}
	map<int, vector<vector<int> > >::iterator iterator = paths.find(target);
	if (iterator != paths.end()) {
		result = iterator->second;
	}
	return result;
}

void CombinationSum::newPath(map<int, vector<vector<int> > > &paths, int a, int b) {
	if (a != 0) {
		map<int, vector<vector<int> > >::iterator i = paths.find(a);
		if (i != paths.end()) {
			vector<vector<int> > p = i->second;
			if (p.size() == 0) {
				vector<int> t;
				t.push_back(b);
				p.push_back(t);
			} else {
				for (vector<vector<int> >::iterator j = p.begin(); j != p.end(); j++) {
					(*j).push_back(b);
				}
			}
			map<int, vector<vector<int> > >::iterator j = paths.find(a+b);
			if (j == paths.end()) {
				paths.insert(pair<int, vector<vector<int> > >(a+b, p));
			} else {
				for (vector<vector<int> >::iterator k = p.begin(); k != p.end(); k++) {
					paths[a+b].push_back(*k);			
				}
			}
		}
	} else {
		vector<int> x;
		x.push_back(b);
		paths[b].push_back(x);
	}
}

CombinationSum::~CombinationSum(void)
{
}
