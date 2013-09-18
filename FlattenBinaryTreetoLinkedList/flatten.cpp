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
        TreeNode * node = root;
        while (node != NULL) {
        	if (node->left != NULL) {
        		TreeNode * aNode = findNode(node->left);
        		aNode->right = node->right;
        		node->right  = node->left;
        		node->left   = NULL;
        	}
        	node = node->right;
        }
    }

    TreeNode * findNode(TreeNode * node) {
    	TreeNode * aNode = node;
    	while (aNode->right != NULL) {
    		aNode = aNode->right;
    	}
    	return aNode;
    }
};