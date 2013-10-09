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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty())
        	return NULL;
        return sortedArrayToBST(num.begin(), num.end());
    }

    TreeNode *sortedArrayToBST(vector<int>::iterator beginIter, vector<int>::iterator endIter) {
    	size_t mid = (endIter - beginIter) / 2;
    	vector<int>::iterator pos = beginIter + mid;
    	TreeNode *node = new TreeNode(*pos);
    	if (pos != beginIter) {
    		node->left = sortedArrayToBST(beginIter, pos);
    	}
    	if (pos + 1 != endIter) {
    		node->right = sortedArrayToBST(pos+1, endIter);
    	}
    	return node;
    }
};