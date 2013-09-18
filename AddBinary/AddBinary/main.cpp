#include <iostream>
#include "AddBinary.h"

using namespace std;

int main() {
	AddBinary addBinary;
	string result = addBinary.addBinary("1", "111");
	cout << result << endl;
	system("pause");
}