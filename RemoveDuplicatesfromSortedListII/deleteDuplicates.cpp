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
        ListNode * newHead = (ListNode*)malloc(sizeof(ListNode));
        newHead->next = head;
        ListNode * prev = newHead;
        ListNode * curr = head;
        bool found = false;
        while (curr->next != NULL) {
        	if (curr->val == curr->next->val) {
        		ListNode *temp = curr->next;
        		curr->next = curr->next->next;
        		free(temp);
        		found = true;
        	} else {
        		if (found) {
        			prev->next = curr->next;
        			ListNode *temp = curr;
        			curr = curr->next;
        			free(temp);
        			found = false;
        		} else {
        			prev = prev->next;
        			curr = curr->next;
        		}
        	}
        }
        if (found)
        	prev->next = NULL;
        ListNode *temp = newHead;
        newHead = newHead->next;
        free(temp);
        return newHead;
    }
};