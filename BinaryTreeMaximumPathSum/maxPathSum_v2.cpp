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
    int maxPathSum(TreeNode *root) {
        if (root == NULL)
        	return 0;
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }

    int maxPathSum(TreeNode *node, int &res) {
    	int left_sum = 0;
    	if (node->left != NULL)
    		left_sum = maxPathSum(node->left, res);
    	int right_sum = 0;
    	if (node->right != NULL)
    		right_sum = maxPathSum(node->right, res);
    	int sum = max(left_sum, right_sum);
    	sum = max(node->val, sum+node->val);
    	res = max(res, sum);
    	res = max(res, left_sum + node->val + right_sum);
    	return sum;
    }
};