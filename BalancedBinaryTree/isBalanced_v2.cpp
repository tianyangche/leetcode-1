/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        int curr = 0;
        return isBalanced(root, curr);
    }

    bool isBalanced(TreeNode *node, int &curr) {
        if (node == NULL)
    		return true;
    	int left = 0;
    	if (!isBalanced(node->left, left))
    		return false;
    	int right = 0;
    	if (!isBalanced(node->right, right))
    		return false;
    	if (abs(left - right) > 1)
    		return false;
    	curr = max(left, right) + 1;
        return true;
    }
};