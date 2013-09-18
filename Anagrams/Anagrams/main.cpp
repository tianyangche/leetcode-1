#include <iostream>
#include "Anagrams.h"

int main() {
	Anagrams anagrams;
	vector<string> strs;
	strs.push_back("cab");
	strs.push_back("tin");
	strs.push_back("pew");
	strs.push_back("duh");
	strs.push_back("may");
	strs.push_back("ill");
	strs.push_back("buy");
	strs.push_back("bar");
	strs.push_back("max");
	strs.push_back("doc");
	vector<string> result = anagrams.anagrams(strs);
	for (vector<string>::iterator i = result.begin(); i != result.end(); i++)
		cout << *i << endl;
	system("pause");
}