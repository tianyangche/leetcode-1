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
    void recoverTree(TreeNode *root) {
        if (!root)
        	return;
        TreeNode *prev = NULL;
        TreeNode *first = NULL, *second = NULL;
        recoverTree(root, prev, first, second);
        swap(first->val, second->val);
    }

    void recoverTree(TreeNode *node, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
    	if (node->left)
    		recoverTree(node->left, prev, first, second);
    	if (prev && prev->val > node->val) {
    		if (!first) {
    			first = prev;
    		}
    		second = node;
    	}
    	prev = node;
    	if (node->right)
    		recoverTree(node->right, prev, first, second);
    }
};