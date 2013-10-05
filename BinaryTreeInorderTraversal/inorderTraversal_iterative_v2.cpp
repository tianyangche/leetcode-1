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
        stack<TreeNode*> recs;
        TreeNode *curr = root;
        while (!recs.empty() || curr) {
            if (curr) {
        		recs.push(curr);
        		curr = curr->left;
        	} else {
        		curr = recs.top();
        		recs.pop();
        		res.push_back(curr->val);
        		curr = curr->right;
        	}
        }
    	return res;
    }
};