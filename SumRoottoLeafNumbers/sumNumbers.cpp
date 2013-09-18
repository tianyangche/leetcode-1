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
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
        	return 0;
        int res = 0;
        travesal(root, 0, res);
    	return res;
    }

    void travesal(TreeNode *node, int curr, int &res) {
    	curr = 10*curr + node->val; 
    	if (node->left == NULL && node->right == NULL) {
    		res += curr;
    		return;
    	}
    	if (node->left != NULL)
    		travesal(node->left, curr, res);
    	if (node->right != NULL)
    		travesal(node->right, curr, res);
    }
};