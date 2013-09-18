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
        if (root == NULL)
            return;
        TreeNode *prev   = NULL;
        TreeNode *first  = NULL;
        TreeNode *second = NULL;
        inorder(root, prev, first, second);
        swap(first->val, second->val);
    }

    void inorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
    	if (root->left != NULL)
    		inorder(root->left, prev, first, second);
    	if (prev != NULL && root->val < prev->val) {
    		if (first == NULL)
    			first = prev;
    		second = root;
    	}
    	prev = root;
    	if (root->right != NULL)
    		inorder(root->right, prev, first, second);
    }
};