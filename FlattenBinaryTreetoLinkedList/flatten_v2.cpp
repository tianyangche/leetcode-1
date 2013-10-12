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
    void flatten(TreeNode *root) {
        if (root == NULL)
        	return;
        if (root->left != NULL) {
        	TreeNode *node = findRightMost(root->left);
        	node->right = root->right;
        	root->right = root->left;
        	root->left  = NULL;
        }
        flatten(root->right);
    }

    TreeNode *findRightMost(TreeNode *root) {
    	TreeNode *node = root;
    	while (node->right != NULL)
    		node = node->right;
    	return node;
    }
};