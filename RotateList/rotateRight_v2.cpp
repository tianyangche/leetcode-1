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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
        	return NULL;
        if (!(head->next))
        	return head;
        int len = getListLength(head);
        k %= len;
        if (k == 0)
        	return head;
        ListNode *node1 = head;
        ListNode *node2 = head;
        int i = 0;
        while (node2->next) {
        	if (i >= k) {
        		node1 = node1->next;
        	}
        	node2 = node2->next;
        	i++;
        }
        node2->next = head;
        head = node1->next;
        node1->next = NULL;
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