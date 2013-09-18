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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL)
        	return false;
        if (q == NULL)
        	return false;
        return checkTree(p, q);
    }

    bool checkTree(TreeNode *p, TreeNode *q) {
    	if (p->val != q->val)
    		return false;
    	if (p->left == NULL && q->left != NULL)
    		return false;
    	if (p->left != NULL && q->left == NULL)
    		return false;
    	bool leftBool = true;
    	if (p->left != NULL && q->left != NULL)
    		leftBool = checkTree(p->left, q->left);
    	if (p->right == NULL && q->right != NULL)
    		return false;
    	if (p->right != NULL && q->right == NULL)
    		return false;
    	bool rightBool = true;
    	if (p->right != NULL && q->right != NULL)
    		rightBool = checkTree(p->right, q->right);
    	return (leftBool && rightBool);
    }
};