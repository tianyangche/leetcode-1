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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
        	return res;
        inorderTraversal(root, res);
    	return res;
    }

    void inorderTraversal(TreeNode *node, vector<int> &res) {
    	if (node->left != NULL)
    		inorderTraversal(node->left, res);
    	res.push_back(node->val);
    	if (node->right != NULL)
    		inorderTraversal(node->right, res);
    }
};