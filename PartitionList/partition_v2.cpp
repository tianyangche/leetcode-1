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
        if (!head)
        	return NULL;
        ListNode *smallerFront = NULL, *smallerNode = NULL;
        ListNode *largerFront  = NULL, *largerNode  = NULL;

        while (head) {
        	if (head->val < x) {
        		if (!smallerFront) {
        			smallerFront = head;
        			smallerNode  = head;
        		} else {
        			smallerNode->next = head;
        			smallerNode = smallerNode->next;
        		}
        	} else {
        		if (!largerFront) {
        			largerFront = head;
        			largerNode  = head;
        		} else {
        			largerNode->next = head;
        			largerNode = largerNode->next;
        		}
        	}
        	head = head->next;
        }

        if (!smallerFront)
        	return largerFront;
        if (!largerFront)
        	return smallerFront;
        smallerNode->next = largerFront;
        largerNode->next  = NULL;
        return smallerFront;
    }
};