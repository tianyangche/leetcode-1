#include <algorithm>
#include "IsBalanced.h"


IsBalanced::IsBalanced(void)
{
}

bool IsBalanced::isBalanced(TreeNode *root) {
	if (root == NULL) {
		return true;
	}
	int height = 0;
	return isBalanced(root, height);
}

bool IsBalanced::isBalanced(TreeNode *root, int &height) {
	if (root->left == NULL && root->right == NULL) {
		height = 1;
		return true;
	} else {
		int left_height = 0, right_height = 0;
		bool left_balanced  = true;
		if (root->left != NULL) {
			left_balanced  = isBalanced(root->left,   left_height);
		}
		bool right_balanced = true;
		if (root->right != NULL) {
			right_balanced = isBalanced(root->right, right_height);
		}if (left_height > right_height) {
			height = left_height + 1;
		} else {
			height = right_height + 1;
		}
		if (!(left_balanced && right_balanced)) {
			return false;
		} else {
			if (abs(left_height - right_height) > 1)
				return false;
			else
				return true;
		}
	}
}

IsBalanced::~IsBalanced(void)
{
}
