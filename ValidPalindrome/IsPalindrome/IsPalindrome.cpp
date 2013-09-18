#include "IsPalindrome.h"
#include <iostream>

IsPalindrome::IsPalindrome(void)
{
}

bool IsPalindrome::isPalindrome(string s) {
	string str;
	for (string::iterator i = s.begin(); i != s.end(); i++) {
		if ((*i >= 'a' && *i <= 'z') || (*i >= 'A' && *i <= 'Z') || (*i >= '0' && *i <= '9')) {
			str += *i;
		}
	}
	cout << str << endl;
	int len = str.length();
	int n   = len / 2;
	for (int i = 0; i < n; i++) {
		if ((str[i] >= '0' && str[i] <= '9') || (str[len-i-1] >= '0' && str[len-i-1] <= '9')) {
			if (str[i] != str[len-i-1])
				return false;
		} else
			if (!charcmp(str[i], str[len-i-1]))
				return false;
	}
	return true;
}

bool IsPalindrome::charcmp(char a, char b) {
	int valuea = 0;
	int valueb = 0;
	cout << a << " " << b << endl;
	if (a >= 'a' && a <= 'z')
		valuea = a - 'a';
	else
		valuea = a - 'A';
	if (b >= 'a' && b <= 'z')
		valueb = b - 'a';
	else
		valueb = b - 'A';
	if (valuea == valueb)
		return true;
	else
		return false;
}

IsPalindrome::~IsPalindrome(void)
{
}
