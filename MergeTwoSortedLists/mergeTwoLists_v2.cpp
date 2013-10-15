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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2)
        	return NULL;
        if (!l1)
        	return l2;
        if (!l2)
        	return l1;
        ListNode *dummy = new ListNode(0);
        ListNode *l3 = dummy;
        while (l1 && l2) {
        	if (l1->val < l2->val) {
        		l3->next = l1;
        		l1 = l1->next;
        		l3 = l3->next;
        		l3->next = NULL;
        	} else {
        		l3->next = l2;
        		l2 = l2->next;
        		l3 = l3->next;
        		l3->next = NULL;
        	}
        }
        l3->next = l1 ? l1 : NULL;
        l3->next = l2 ? l2 : l3->next;
        ListNode *head = dummy->next;
        free(dummy);
        return head;
    }
};