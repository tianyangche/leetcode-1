#include "Anagrams.h"

Anagrams::Anagrams(void)
{
}

vector<string> Anagrams::anagrams(vector<string> &strs) {
	map<string, vector<string>> store;
	vector<string> result;
	for (vector<string>::iterator i = strs.begin(); i != strs.end(); i++) {
		string pattern = *i;
		sort(pattern.begin(), pattern.end());
		store[pattern].push_back(*i);
	}
	for (map<string, vector<string>>::iterator i = store.begin(); i != store.end(); i++) {
		if (i->second.size() > 1) {
			for (vector<string>::iterator j = i->second.begin(); j != i->second.end(); j++) {
				result.push_back(*j);
			}
		}
	}
	return result;
}

