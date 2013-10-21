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
        if (!root)
        	return false;
        return hasPathSum(root, 0, sum);
    }

    bool hasPathSum(TreeNode *root, int curr, int sum) {
    	if (!root)
    		return false;
    	if (!root->left && !root->right) {
    		return root->val + curr == sum ? true : false;
    	}
    	if (hasPathSum(root->left, root->val+curr, sum))
    		return true;
    	if (hasPathSum(root->right, root->val+curr, sum))
    		return true;
    	return false;
    }
};