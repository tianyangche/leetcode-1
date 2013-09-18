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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> path;
        path.push_back(root->val);
        findPathSum(res, path, root, root->val, sum);
        return res;
    }

    void findPathSum(vector<vector<int>> &res, vector<int> &path, TreeNode *node, int curr, int sum) {
    	if (curr == sum && node->left == NULL && node->right == NULL) {
    		res.push_back(path);
    		return;
    	}
    	if (node->left != NULL) {
    		path.push_back(node->left->val);
    		findPathSum(res, path, node->left, curr+node->left->val, sum);
    		path.pop_back();
    	}
    	if (node->right != NULL) {
    		path.push_back(node->right->val);
    		findPathSum(res, path, node->right, curr+node->right->val, sum);
    		path.pop_back();
    	}
    }
};