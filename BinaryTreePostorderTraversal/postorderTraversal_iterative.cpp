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
        stack<TreeNode*> recs;
        recs.push(root);
        while (!recs.empty()) {
            TreeNode *node = recs.top();
            recs.pop();
            res.push_back(node->val);
            if (node->left)
                recs.push(node->left);
            if (node->right)
                recs.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};