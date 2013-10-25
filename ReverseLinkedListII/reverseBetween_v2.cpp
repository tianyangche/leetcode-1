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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	if (!head)
    		return NULL;
    	ListNode **node = &head;
    	int i = 0;
    	while (i < m - 1) {
    		node = &((*node)->next);
    		i++;
    	}
    	i = 0;
    	ListNode *tail = *node;
    	while (i < n - m) {
    		ListNode *p = tail->next;
    		tail->next = p->next;
    		p->next = *node;
    		*node = p;
    		i++;
    	}
    	return head;
    }
};