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
        if (head == NULL || k <= 1)
            return head;
        ListNode *newHead = (ListNode*)malloc(sizeof(ListNode));
        newHead->next = head;
        ListNode *prev = newHead;
        ListNode *curr = newHead;
        int step = 0;
        while (curr != NULL) {
        	if (step < k) {
        		curr = curr->next;
        		step++;
        	} else {
        		ListNode *node = prev->next;
        		while (step > 1) {
        			ListNode *temp = prev->next;
        			prev->next = node->next;
        			node->next = node->next->next;
        			prev->next->next = temp;
        			step--;
        		}
        		prev = node;
        		curr = node->next;
        	}
        }
        ListNode *res = newHead->next;
        free(newHead);
        return res;
    }
};