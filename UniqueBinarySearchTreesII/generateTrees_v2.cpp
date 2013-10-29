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
    vector<TreeNode *> generateTrees(int n) {
        if (n < 1)
        	return generateTrees(1, 0);
        else
        	return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int begin, int end) {
    	vector<TreeNode *> res;
    	if (begin > end) {
    		res.push_back(NULL);
    		return res;
    	}
    	for (int root = begin; root <= end; root++) {
    		vector<TreeNode *> left  = generateTrees(begin, root-1);
    		vector<TreeNode *> right = generateTrees(root+1, end);
    		for (int i = 0; i < left.size(); i++) {
    			for (int j = 0; j < right.size(); j++) {
    				TreeNode *node = new TreeNode(root);
    				node->left  = left[i];
    				node->right = right[j];
    				res.push_back(node);
    			}
    		}
    	}
    	return res;
    }
};