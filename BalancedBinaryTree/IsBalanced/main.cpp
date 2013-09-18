#include <iostream>
#include "IsBalanced.h"

using namespace std;

int main() {
	TreeNode node1(10);
	TreeNode node2(20);
	TreeNode node3(30);
	//node1.left = &node2;
	node1.right = &node3;
	IsBalanced isbalanced;
	bool balanced = isbalanced.isBalanced(&node1);
	cout << balanced << endl;
	system("pause");
}