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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        res.push_back(root->val);
        vector<int> left  = preorderTraversal(root->left);
        if (!left.empty())
            res.insert(res.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right);
        if (!right.empty())
            res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};