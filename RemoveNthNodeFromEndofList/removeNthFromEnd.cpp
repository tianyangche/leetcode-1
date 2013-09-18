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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;
        ListNode *node = head;
        ListNode *del  = head;
        ListNode *prev = (ListNode*)malloc(sizeof(ListNode));
        prev->next = head;
        ListNode *temp = prev;
        int k = 1;
        while (node->next != NULL) {
        	node = node->next;
        	if (k >= n) {
        		prev = del;
        		del = del->next;
        	}
            k++;
        }
        if (k >= n) {
        	prev->next = del->next;
        	free(del);
        }
        ListNode *result = temp->next;
        free(temp);
        return result;
    }
};