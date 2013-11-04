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
    bool isValidBST(TreeNode *root) {
        if (!root)
        	return true;
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode *node, int lower, int upper) {
    	if (!node)
    		return true;
    	if (node->val < lower || node->val > upper)
    		return false;
    	if (!isValidBST(node->left, lower, node->val-1))
    		return false;
    	return isValidBST(node->right, node->val+1, upper);
    }
};