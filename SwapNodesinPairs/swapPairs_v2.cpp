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
    ListNode *swapPairs(ListNode *head) {
        if (!head)
        	return NULL;
        ListNode **node = &head;
        while (*node && (*node)->next) {
        	ListNode *p = (*node)->next;
        	(*node)->next = p->next;
        	p->next = *node;
        	*node = p;
        	node = &((*node)->next->next);
        }
        return head;
    }
};