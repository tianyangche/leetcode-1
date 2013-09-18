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
        if (l1 == NULL && l2 == NULL)
        	return NULL;
        if (l1 == NULL)
        	return l2;
        if (l2 == NULL)
        	return l1;
        ListNode *head = (ListNode*)malloc(sizeof(ListNode));
        head->next = l1;
        ListNode *prev1 = head;
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        while (curr1 != NULL && curr2 != NULL) {
        	if (curr1->val < curr2->val) {
        		prev1  = curr1;
        		curr1 = curr1->next;
        	} else {
        		prev1->next = curr2;
        		prev1 = prev1->next;
        		curr2 = curr2->next;
        		prev1->next = curr1;
        	}
        }
        if (curr2 != NULL) {
        	prev1->next = curr2;
        }
        prev1 = head;
        head = head->next;
        free(prev1);
        return head;
    }
};