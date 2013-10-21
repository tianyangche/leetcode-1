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
        if (!root)
        	return;
        vector<TreeLinkNode *> recs;
        recs.push_back(root);
        buildNext(recs);
    }

    void buildNext(vector<TreeLinkNode *> &recs) {
    	vector<TreeLinkNode *> nextRecs;
    	for (auto iter = recs.begin(); iter != recs.end(); iter++) {
    		(*iter)->next = iter + 1 != recs.end() ? *(iter + 1) : NULL;
    		if ((*iter)->left)
    			nextRecs.push_back((*iter)->left);
    		if ((*iter)->right)
    			nextRecs.push_back((*iter)->right);
    	}
    	if (!nextRecs.empty())
    		buildNext(nextRecs);
    }
};