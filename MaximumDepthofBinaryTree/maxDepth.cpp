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
        if (root == NULL)
        	return 0;
        int depth = 0;
        findMaxDepth(root, 0, depth);
        return depth;
    }

    void findMaxDepth(TreeNode * root, int currDep, int &depth) {
    	if (root == NULL) {
    		depth = max(depth, currDep);
    	} else {
    		findMaxDepth(root->left,  currDep+1, depth);
    		findMaxDepth(root->right, currDep+1, depth);
    	}
    }
};