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
            return generate(1, 0);
        else
        	return generate(1, n);
    }

    vector<TreeNode *> generate(int begin, int end) {
    	vector<TreeNode *> tree;
    	if (begin > end) {
    		tree.push_back(NULL);
    		return tree;
    	}
    	for (int i = begin; i <= end; i++) {
    		vector<TreeNode *> leftsubtree  = generate(begin, i-1);
    		vector<TreeNode *> rightsubtree = generate(i+1, end);
    		for (int j = 0; j < leftsubtree.size(); j++) {
    			for (int k = 0; k < rightsubtree.size(); k++) {
    				TreeNode * node = new TreeNode(i);
    				node->left  = leftsubtree[j];
    				node->right = rightsubtree[k];
    				tree.push_back(node);
    			}
    		}
    	}
    	return tree;
    }
};