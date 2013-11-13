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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        postorderTraversal(root, res);
        return res;
    }
    
    void postorderTraversal(TreeNode *node, vector<int> &res) {
        if (!node)
            return;
        postorderTraversal(node->left, res);
        postorderTraversal(node->right, res);
        res.push_back(node->val);
    }
};