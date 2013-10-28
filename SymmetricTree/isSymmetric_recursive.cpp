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
    bool isSymmetric(TreeNode *root) {
        return !root ? true : isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *lnode, TreeNode *rnode) {
        if (!lnode && !rnode)
            return true;
        if (!lnode || !rnode)
            return false;
        return (lnode->val == rnode->val) 
                && isSymmetric(lnode->left, rnode->right) 
                && isSymmetric(lnode->right, rnode->left);
    }
};