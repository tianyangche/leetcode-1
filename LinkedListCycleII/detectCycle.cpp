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
    ListNode *detectCycle(ListNode *head) {
        if (!head)
        	return NULL;
        ListNode *node1 = head;
        ListNode *node2 = head;
        while (node1 && node2) {
        	node1 = node1->next;
        	node2 = node2->next;
        	if (!(node1 && node2)) {
        		return NULL;
        	}
        	node2 = node2->next;
        	if (!node2) {
        		return NULL;
        	}
        	if (node1 == node2) {
        		break;
        	}
        }
        node1 = head;
        while (node1 != node2) {
        	node1 = node1->next;
        	node2 = node2->next;
        }
        return node1;
    }
};