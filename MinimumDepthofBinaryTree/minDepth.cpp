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
        if (root == NULL)
        	return 0;
       	int minDepth = INT_MAX;
       	findMinDepth(root, 1, minDepth);
       	return minDepth;
    }

    void findMinDepth(TreeNode *root, int depth, int &minDepth) {
    	
    	if (root->left == NULL && root->right == NULL) {
    		minDepth = depth < minDepth ? depth : minDepth;
    	} else {
    		if (root->left != NULL) {
    			findMinDepth(root->left, depth+1, minDepth);
    		}
    		if (root->right != NULL) {
    			findMinDepth(root->right, depth+1, minDepth);
    		}
    	}
    }
};