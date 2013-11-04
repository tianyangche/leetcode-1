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
    bool hasCycle(ListNode *head) {
        if (!head)
        	return false;
        ListNode *node1 = head;
        ListNode *node2 = head;
        while (node2) {
        	node1 = node1->next;
        	node2 = node2->next;
        	if (!node1 || !node2)
        		return false;
        	node2 = node2->next;
        	if (node1 == node2)
        		return true;
        }
    }
};