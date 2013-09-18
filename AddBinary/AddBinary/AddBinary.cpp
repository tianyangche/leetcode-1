#include "AddBinary.h"

AddBinary::AddBinary(void)
{
}

string AddBinary::addBinary(string a, string b) {
	string result;
	int iter_a = a.size() - 1;
	int iter_b = b.size() - 1;
	int temp = 0;
	while (iter_a >= 0 && iter_b >= 0) {
		int value_a = a[iter_a] - '0';
		int value_b = b[iter_b] - '0';
		int sum = value_a + value_b + temp;
		if (sum > 1) {
			sum -= 2;
			temp = 1;
		} else {
			temp = 0;
		}
		char ch = sum + '0';
		result.push_back(ch);
		iter_a--;
		iter_b--;
	}
	while (iter_a >= 0) {
		int value = a[iter_a] - '0';
		int sum   = value + temp;
		if (sum == 2) {
			sum  = 0;
			temp = 1;
		} else {
			temp = 0;
		}
		char ch = sum + '0';
		result.push_back(ch);
		iter_a--;
	}
	while (iter_b >= 0) {
		int value = b[iter_b] - '0';
		int sum   = value + temp;
		if (sum == 2) {
			sum  = 0;
			temp = 1;
		} else {
			temp = 0;
		}
		char ch = sum + '0';
		result.push_back(ch);
		iter_b--;
	}
	if (temp != 0)
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}

AddBinary::~AddBinary(void)
{
}
