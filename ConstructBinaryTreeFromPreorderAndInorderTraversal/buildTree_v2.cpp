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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        if (preorder.size() != inorder.size())
        	return NULL;
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode *buildTree(vector<int>::iterator preBeginIter, vector<int>::iterator preEndIter, vector<int>::iterator inBeginIter, vector<int>::iterator inEndIter) {
    	TreeNode *node = new TreeNode(*preBeginIter);
    	vector<int>::iterator pos = find(inBeginIter, inEndIter, *preBeginIter);
    	size_t i = pos - inBeginIter;
    	if (i != 0) {
    		node->left = buildTree(preBeginIter+1, preBeginIter+i, inBeginIter, pos);
    	}
    	if (pos + 1 != inEndIter) {
    		node->right = buildTree(preBeginIter+i+1, preEndIter, pos+1, inEndIter);
    	}
    	return node;
    }
};