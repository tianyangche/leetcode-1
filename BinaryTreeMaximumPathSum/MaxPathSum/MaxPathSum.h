#pragma once
#include <stddef.h>

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MaxPathSum
{
public:
	MaxPathSum(void);
	int maxPathSum(TreeNode *root);
	int maxPathSum(TreeNode *root, int &maxSum);
	~MaxPathSum(void);
};

