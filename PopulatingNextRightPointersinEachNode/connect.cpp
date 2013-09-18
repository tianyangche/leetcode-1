/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
        	return;
        vector<TreeLinkNode*> currLevel;
        currLevel.push_back(root);
    	traversal(currLevel);
    }

    void traversal(vector<TreeLinkNode*> currLevel) {
    	vector<TreeLinkNode*> nextLevel;
    	for (int i = 0; i < currLevel.size(); i++) {
    		if (i + 1 < currLevel.size()) {
    			currLevel[i]->next = currLevel[i+1];
    		} else {
    			currLevel[i]->next = NULL;
    		}
    		if (currLevel[i]->left != NULL)
    			nextLevel.push_back(currLevel[i]->left);
    		if (currLevel[i]->right != NULL)
    			nextLevel.push_back(currLevel[i]->right);
    	}
    	if (!nextLevel.empty())
    		traversal(nextLevel);
    }
};