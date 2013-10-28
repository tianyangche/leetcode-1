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
    bool isSymmetric(TreeNode *root) {
        if (!root)
        	return true;
        vector<TreeNode*> nodes(1, root);
        return isSymmetric(nodes);
    }

    bool isSymmetric(vector<TreeNode*> &nodes) {
    	vector<TreeNode*> nodes1;
    	vector<TreeNode*> nodes2;
    	int i = 0;
    	int j = nodes.size() - 1;
    	while (i <= j) {
    		TreeNode *left  = nodes[i];
    		TreeNode *right = nodes[j];
    		if (left->val != right->val)
    			return false;
    		if ((!left->left && right->right) || (left->left && !right->right))
    			return false;
    		if ((!left->right && right->left) || (left->right && !right->left))
    			return false;
    		if (left->left)
    			nodes1.push_back(left->left);
    		if (left->right)
    			nodes1.push_back(left->right);
    		if (right->right)
    			nodes2.insert(nodes2.begin(), right->right);
    		if (right->left)
    			nodes2.insert(nodes2.begin(), right->left);
    		i++; j--;
    	}
    	nodes1.insert(nodes1.end(), nodes2.begin(), nodes2.end());
    	return nodes1.empty() ? true : isSymmetric(nodes1);
    }
};