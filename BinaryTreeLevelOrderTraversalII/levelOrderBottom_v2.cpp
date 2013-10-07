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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL)
            return res;
        queue<TreeNode*> prev;
        prev.push(root);
        stack<vector<int> > temp;
        while (true) {
        	queue<TreeNode*> curr;
        	vector<int> oneAns;
        	while (!prev.empty()) {
        		TreeNode *node = prev.front();
        		prev.pop();
        		oneAns.push_back(node->val);
        		if (node->left != NULL)
        			curr.push(node->left);
        		if (node->right != NULL)
        			curr.push(node->right);
        	}
        	temp.push(oneAns);
        	prev = curr;
        	if (prev.empty())
        		break;
        }
        while (!temp.empty()) {
        	vector<int> oneAns = temp.top();
        	temp.pop();
        	res.push_back(oneAns);
        }
        return res;
    }
};