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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL)
        	return res;
        queue<TreeNode*> prev;
        prev.push(root);
        while (true) {
        	queue<TreeNode*> curr;
        	vector<int> recs;
        	while (!prev.empty()) {
        		TreeNode *node = prev.front();
        		prev.pop();
        		recs.push_back(node->val);
        		if (node->left != NULL)
        			curr.push(node->left);
        		if (node->right != NULL)
        			curr.push(node->right);
        	}
        	res.push_back(recs);
        	if (curr.empty())
        		break;
        	prev = curr;
        }
        return res;
    }
};