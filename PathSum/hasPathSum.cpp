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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return 0;
       	return isPathSum(root, 0, sum);
    }

    bool isPathSum(TreeNode *node, int curr, int sum) {
    	curr += node->val;
    	if (curr == sum && node->left == NULL && node->right == NULL)
    		return true;
    	if (node->left != NULL)
    		if (isPathSum(node->left, curr, sum))
    			return true;
    	if (node->right != NULL)
    		if (isPathSum(node->right, curr, sum))
    			return true;
    	return false;
    }
};