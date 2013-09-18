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
        if (root == NULL)
            return true;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        return checkSymmetric(nodes);
    }

    bool checkSymmetric(vector<TreeNode*> &nodes) {
    	vector<TreeNode*> nextNodes1;
    	vector<TreeNode*> nextNodes2;
    	int i = 0;
    	int j = nodes.size() - 1;
    	while (i <= j) {
    		if (!(nodes[i]->val == nodes[j]->val 
    			&& ((nodes[i]->left == NULL && nodes[j]->right == NULL) || (nodes[i]->left != NULL && nodes[j]->right != NULL)) 
    			&& ((nodes[i]->right == NULL && nodes[j]->left == NULL) || (nodes[i]->right != NULL && nodes[j]->left != NULL)) ))
    			return false;
    		if (nodes[i]->left != NULL)
    			nextNodes1.push_back(nodes[i]->left);
    		if (nodes[i]->right != NULL)
    			nextNodes1.push_back(nodes[i]->right);
    		if (nodes[j]->right != NULL)
    			nextNodes2.insert(nextNodes2.begin(), nodes[j]->right);
    		if (nodes[j]->left != NULL)
    			nextNodes2.insert(nextNodes2.begin(), nodes[j]->left);
    		i++;
    		j--;
    	}
    	if (!nextNodes1.empty())
    		nextNodes1.insert(nextNodes1.end(), nextNodes2.begin(), nextNodes2.end());
    	else
    		nextNodes1 = nextNodes2;
    	if (!nextNodes1.empty())
    		return checkSymmetric(nextNodes1);
    	else
    		return true;
    }
};