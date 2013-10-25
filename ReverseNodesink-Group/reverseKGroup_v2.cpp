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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head)
        	return NULL;
        if (k <= 1)
        	return head;
        int len = getListLength(head);
        if (len < k)
        	return head;
        ListNode **first = &head;
        ListNode *node = *first;
        while (k <= len && node) {
        	for (int i = 1; i < k; i++) {
        		ListNode *p = node->next;
        		node->next  = p->next;
        		p->next = *first;
        		*first  = p;
        	}
        	first = &(node->next);
        	node  = *first;
        	len -= k;
        }
        return head;
    }

    int getListLength(ListNode *head) {
    	int len = 0;
    	while (head) {
    		head = head->next;
    		len++;
    	}
    	return len;
    }
};