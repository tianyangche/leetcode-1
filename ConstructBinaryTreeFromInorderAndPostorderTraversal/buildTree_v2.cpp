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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty())
            return NULL;
        if (inorder.size() != postorder.size())
        	return NULL;
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode *buildTree(vector<int>::iterator inBeginIter, vector<int>::iterator inEndIter, vector<int>::iterator postBeginIter, vector<int>::iterator postEndIter) {
    	TreeNode *node = new TreeNode(*(postEndIter-1));
    	vector<int>::iterator pos = find(inBeginIter, inEndIter, *(postEndIter-1));
    	size_t i = pos - inBeginIter;
    	if (i != 0) {
    		node->left = buildTree(inBeginIter, pos, postBeginIter, postBeginIter+i);
    	}
    	if (pos + 1 != inEndIter) {
    		node->right = buildTree(pos+1, inEndIter, postBeginIter+i, postEndIter-1);
    	}
    	return node;
    }
};