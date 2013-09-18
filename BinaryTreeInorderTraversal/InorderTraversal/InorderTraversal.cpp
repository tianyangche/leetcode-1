#include "InorderTraversal.h"


InorderTraversal::InorderTraversal(void)
{
}

vector<int> InorderTraversal::inorderTraversal(TreeNode *root) {
	vector<int> result;
	if (root == NULL)
          return result;
	inorderTraversal(root, result);
	return result;
}

void InorderTraversal::inorderTraversal(TreeNode *root, vector<int> &result) {
	if (root->left != NULL)
		inorderTraversal(root->left, result);
	result.push_back(root->val);
	if (root->right != NULL)
		inorderTraversal(root->right, result);
}

InorderTraversal::~InorderTraversal(void)
{
}
