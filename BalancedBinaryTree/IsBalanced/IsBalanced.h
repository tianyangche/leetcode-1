#include <stddef.h>

#pragma once

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class IsBalanced
{
public:
	IsBalanced(void);
	bool isBalanced(TreeNode *root);
	bool isBalanced(TreeNode *root, int &height);
	~IsBalanced(void);
};

