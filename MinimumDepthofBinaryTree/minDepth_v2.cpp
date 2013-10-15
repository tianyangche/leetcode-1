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
    int minDepth(TreeNode *root) {
        if (!root)
        	return 0;
        int minHeight = INT_MAX;
        findMinDepth(root, 1, minHeight);
        return minHeight;
    }

    void findMinDepth(TreeNode *node, int currHeight, int &minHeight) {
    	if (!node->left && !node->right) {
    		minHeight = min(minHeight, currHeight);
    		return;
    	}
    	if (node->left)
    		findMinDepth(node->left,  currHeight+1, minHeight);
    	if (node->right)
    		findMinDepth(node->right, currHeight+1, minHeight);
    }
};