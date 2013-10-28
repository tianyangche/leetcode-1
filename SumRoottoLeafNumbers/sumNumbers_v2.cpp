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
    int sumNumbers(TreeNode *root) {
        if (!root)
        	return 0;
        int ans = 0;
        sumNumbers(root, 0, ans);
        return ans;
    }

    void sumNumbers(TreeNode *root, int sum, int &ans) {
    	sum = 10 * sum + root->val;
    	if (!root->left && !root->right) {
    		ans += sum;
    		return;
    	}
    	if (root->left)
    		sumNumbers(root->left, sum, ans);
    	if (root->right)
    		sumNumbers(root->right, sum, ans);
    }
}; 