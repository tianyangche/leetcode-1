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
        
        TreeNode *node = (TreeNode *)malloc(sizeof(struct TreeNode));
        node->left  = NULL;
        node->right = NULL;
        if (num.empty())
            return NULL;
        transform(node, num.begin(), num.end());
        return node;
    }

    void transform(TreeNode * node, vector<int>::iterator begin, vector<int>::iterator end) {
    	int size = end - begin;
    	if (size == 1) {
    		node->val = *begin;
    	} else {
    		int pos = size / 2;
    		node->val = *(begin+pos);
    		if (pos > 0) {
    			TreeNode * newNode = (TreeNode *)malloc(sizeof(struct TreeNode));
    			newNode->left  = NULL;
    			newNode->right = NULL;
                node->left = newNode;
    			transform(newNode, begin, begin+pos);
    		}
    		if (begin + pos < end - 1) {
    			TreeNode * newNode = (TreeNode *)malloc(sizeof(struct TreeNode));
    			newNode->left  = NULL;
    			newNode->right = NULL;
                node->right = newNode;
    			transform(newNode, begin+pos+1, end);
    		}
    	}
    }
};