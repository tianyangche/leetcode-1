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
        if (!head || !(head->next))
        	return head;
        ListNode **node = &(head->next);
        int currVal = head->val;
        while (*node) {
        	if ((*node)->val == currVal) {
        		ListNode *delNode = *node;
        		(*node) = (*node)->next;
        		free(delNode);
        	} else {
        		currVal = (*node)->val;
        		node = &((*node)->next);
        	}
        }
        return head;
    }
};