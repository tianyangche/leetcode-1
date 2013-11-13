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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        stack<TreeNode*> st;
        st.emplace(root);
        int height = 0;
        TreeNode *curr;
        TreeNode *prev = NULL;
        while (!st.empty()) {
            curr = st.top();
            if (!prev || prev->left == curr || prev->right == curr) {
                if (curr->left)
                    st.emplace(curr->left);
                else if (curr->right)
                    st.emplace(curr->right);
            } else if (curr->left = prev) {
                if (curr->right)
                    st.emplace(curr->right);
            } else {
                st.pop();
            }
            prev = curr;
            height = st.size() > height ? st.size() : height;
        }
        return height;
    }
};