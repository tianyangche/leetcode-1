#include <iostream>
#include "MaxPathSum.h"

using namespace std;

int main() {
	TreeNode node1(0);
	TreeNode node2(1);
	TreeNode node3(1);
	node1.left  = &node2;
	node1.right = &node3;
	MaxPathSum maxPathSum;
	int result  = maxPathSum.maxPathSum(&node1);
	cout << result << endl;
	system("pause");
}