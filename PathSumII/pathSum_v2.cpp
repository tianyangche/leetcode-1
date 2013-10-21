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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if (!root)
        	return res;
        vector<int> oneResult;
        pathSum(root, 0, sum, oneResult, res);
        return res;
    }

    void pathSum(TreeNode *node, int curr, int sum, vector<int> &oneResult, vector<vector<int> > &res) {
    	if (!node)
    		return;
    	oneResult.push_back(node->val);
    	if (!node->left && !node->right) {
    		if (node->val + curr == sum) {
    			res.push_back(oneResult);
    	        oneResult.pop_back();
    			return;
    		}
    	}
    	pathSum(node->left,  node->val+curr, sum, oneResult, res);
    	pathSum(node->right, node->val+curr, sum, oneResult, res);
    	oneResult.pop_back();
    }
};