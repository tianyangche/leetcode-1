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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode * newHead = (ListNode*)malloc(sizeof(ListNode));
        newHead->next = head;
        ListNode * node0 = newHead;
        ListNode * node1 = head;
        ListNode * node2 = head->next;
        while (node1 != NULL && node2 != NULL) {
        	node1->next = node2->next;
        	node0->next = node2;
        	node2->next = node1;
        	node0 = node1;
        	node1 = node1->next;
        	if (node1 == NULL)
        		break;
        	node2 = node1->next;
        }
        ListNode *res = newHead->next;
        free(newHead);
        return res;
    }
};