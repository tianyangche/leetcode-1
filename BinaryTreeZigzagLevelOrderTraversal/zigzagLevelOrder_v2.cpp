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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL)
            return res;
        queue<TreeNode*> prev;
        prev.push_back(root);
        bool flag = true;
        while (!prev.empty()) {
        	vector<int> oneLevel;
        	queue<TreeNode*> curr;
        	while (!prev.empty()) {
                TreeNode *node = prev.front();
                prev.pop();
        		oneLevel.push_back(node->val);
        		if (node->left != NULL)
        			curr.push_back(node->left);
        		if (node->right != NULL)
        			curr.push_back(node->right);
        	}
            if (!flag)
                reverse(oneLevel.begin(), oneLevel.end());
        	res.push_back(oneLevel);
        	prev = curr;
        	flag = !flag;
        }
        return res;
    }
};