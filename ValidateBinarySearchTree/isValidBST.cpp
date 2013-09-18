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
        if (root == NULL)
            return true;
        return bst(root, INT_MIN, INT_MAX);
    }

    bool bst(TreeNode *root, int min, int max) {
    	if (!(root->val > min && root->val < max))
    		return false;
    	if (root->left != NULL)
    		if (!bst(root->left, min, root->val))
    			return false;
    	if (root->right != NULL)
    		if (!bst(root->right, root->val, max))
    			return false;
    	return true;
    }
};