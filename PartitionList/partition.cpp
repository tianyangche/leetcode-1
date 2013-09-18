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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
            return NULL;
        ListNode * newHead = (ListNode*)malloc(sizeof(ListNode));
        newHead->next = head;
        ListNode * less = newHead;
        while (less->next != NULL && less->next->val < x)
            less = less->next;
        if (less->next != NULL) {
			ListNode * curr = less->next;
        	while (curr->next != NULL) {
        		if (curr->next->val < x) {
        			ListNode *next = curr->next;
        			curr->next = next->next;
        			next->next = less->next;
        			less->next = next;
        			less = next;
        		} else {
        			curr = curr->next;
        		}
        	}
        }
        ListNode * res = newHead->next;
        free(newHead);
        return res;
    }
};