/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
        	return NULL;
        int i = 0;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode **prev = &(dummyNode->next);
        ListNode *node = head;
        while (node) {
        	if (i >= n) {
        		prev = &((*prev)->next);
        	}
        	node = node->next;
        	i++;
        }
        ListNode *delNode = *prev;
        *prev = (*prev)->next;
        free(delNode);
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};