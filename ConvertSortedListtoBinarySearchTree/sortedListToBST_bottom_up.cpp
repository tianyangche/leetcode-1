/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *node = head;
        int len = 0;
        while (node) {
            node = node->next;
            len++;
        }
        return sortedListToBST(head, 0, len-1);
    }
    
    TreeNode *sortedListToBST(ListNode*& listNode, int lower, int higher) {
        
        if (lower > higher)
            return NULL;
        int mid = (lower + higher) / 2;
        TreeNode *left = sortedListToBST(listNode, lower, mid-1);
        TreeNode *root = new TreeNode(listNode->val);
        root->left = left;
        listNode = listNode->next;
        root->right = sortedListToBST(listNode, mid+1, higher);
    }
};