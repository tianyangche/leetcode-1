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
        if (root->left) {
            root->left->next = root->right ? root->right : getNext(root);
        }
        if (root->right) {
            root->right->next = getNext(root);
        }
        connect(root->right);
        connect(root->left);
    }

    TreeLinkNode *getNext(TreeLinkNode *root) {
        while (root->next) {
            root = root->next;
            if (root->left)
                return root->left;
            if (root->right)
                return root->right;
        }
        return NULL;
    }
};