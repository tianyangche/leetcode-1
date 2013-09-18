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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
        	return NULL;
        ListNode *tail = head;
        ListNode *curr = head->next;
        while (curr != NULL) {
        	if (tail->val < curr->val) {
        		tail->next = curr;
        		curr = curr->next;
        		tail = tail->next;
        	} else {
        		ListNode *temp = curr;
        		curr = curr->next;
        		free(temp);
        	}
        }
        tail->next = NULL;
        return head;
    }
};