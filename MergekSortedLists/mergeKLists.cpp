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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return NULL;
        ListNode *head = (ListNode*)malloc(sizeof(ListNode));
        ListNode *currNode1 = lists[0];
        head->next = currNode1;
        ListNode *prevNode1 = head;
        ListNode *currNode2 = lists[0];
        for (int i = 1; i < lists.size(); i++) {
        	prevNode1 = head;
        	currNode1 = prevNode1->next;
        	currNode2 = lists[i];
        	while (currNode1 != NULL && currNode2 != NULL) {
        		if (currNode1->val < currNode2->val) {
        			prevNode1 = currNode1;
        			currNode1 = currNode1->next;
        		} else {
        			prevNode1->next = currNode2;
        			prevNode1 = prevNode1->next;
        			currNode2 = currNode2->next;
        			prevNode1->next = currNode1;
        		}
        	}
        	if (currNode2 != NULL) {
        		prevNode1->next = currNode2;
        	}
        }
        prevNode1 = head;
        head = head->next;
        free(prevNode1);
        return head;
    }
};