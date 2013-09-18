#include "MaxPathSum.h"
#include <iostream>

using namespace std;

MaxPathSum::MaxPathSum(void)
{
}

int MaxPathSum::maxPathSum(TreeNode *root) {
	if (root == NULL)
		return 0;
	int value = root->val;
	maxPathSum(root, value);
	return value;
}

int MaxPathSum::maxPathSum(TreeNode *root, int &maxSum) {
	int leftMax   = 0;
	int rightMax  = 0;
	int returnVal = root->val;
	int pathSum   = root->val;
	if (root->left != NULL) {
		leftMax = maxPathSum(root->left, maxSum);
	}
	if (root->right != NULL) {
		rightMax = maxPathSum(root->right, maxSum);
	}
	if (leftMax > 0)
		pathSum += leftMax;
	if (rightMax > 0)
		pathSum += rightMax;
	if (maxSum < pathSum)
		maxSum = pathSum;
	if (returnVal < leftMax  + root->val)
		returnVal = leftMax  + root->val;
	if (returnVal < rightMax + root->val)
		returnVal = rightMax + root->val;
	return returnVal;
}

MaxPathSum::~MaxPathSum(void)
{
}
