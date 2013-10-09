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
        if (head == NULL)
            return NULL;
        ListNode *tail = findTailNode(head);
        ListNode *newTail = new ListNode(0);
        tail->next = newTail;
        TreeNode *node = sortedListToBST(head, newTail);
        free(newTail);
        tail->next = NULL;
        return node;
    }

    TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
        int len = findListLength(head, tail);
    	ListNode *listNode = findListNode(head, len/2);
    	TreeNode *treeNode = new TreeNode(listNode->val);
    	if (listNode != head) {
    		treeNode->left = sortedListToBST(head, listNode);
    	}
    	if (listNode->next != tail) {
    		treeNode->right = sortedListToBST(listNode->next, tail);
    	}
    	return treeNode;
    }

    ListNode *findListNode(ListNode *head, int pos) {
    	if (head == NULL)
    		return NULL;
    	int curr = 0;
    	ListNode *node = head;
    	while (node != NULL && curr < pos) {
    		node = node->next;
    		curr++;
    	}
    	return node;
    }

    int findListLength(ListNode *head, ListNode *tail) {
    	if (head == NULL)
    		return 0;
    	ListNode *node = head;
    	int len = 0;
    	while (node != tail) {
    		node = node->next;
    		len++;
    	}
    	return len;
    }

    ListNode *findTailNode(ListNode *head) {
    	if (head == NULL)
    		return NULL;
    	ListNode *node = head;
    	while (node->next != NULL) {
    		node = node->next;
    	}
    	return node;
    }
};