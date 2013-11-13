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
        stack<TreeNode*> st;
        st.emplace(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right)
                st.emplace(node->right);
            if (node->left)
                st.emplace(node->left);
        }
        return res;
    }
};