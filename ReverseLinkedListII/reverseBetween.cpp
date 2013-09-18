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
        if (head == NULL || m == n)
            return head;
        ListNode *newHead = (ListNode*)malloc(sizeof(ListNode));
        newHead->next = head;
        ListNode *node = newHead;
        ListNode *prev = newHead;
        int k = 0;
        while (node->next != NULL && k < n) {
        	if (k < m) {
        		prev = node;
        		node = node->next;
        	} else {
        		ListNode *temp = prev->next;
        		prev->next = node->next;
        		node->next = node->next->next;
        		prev->next->next = temp;
        	}
        	k++;
        }
        ListNode* res = newHead->next;
        free(newHead);
        return res;
    }
};