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
        if (lists.size() < 1)
        	return lists[0];
        ListNode *l1 = lists[0];
        for (vector<ListNode*>::size_type i = 1; i < lists.size(); i++) {
        	ListNode *l2 = lists[i];
        	l1 = merge(l1, l2);
        }
        return l1;
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
    	ListNode *dummy = new ListNode(0);
    	ListNode *curr  = dummy;
    	while (l1 && l2) {
    		if (l1->val < l2->val) {
    			curr->next = l1;
    			l1 = l1->next;
    			curr = curr->next;
    			curr->next = NULL;
    		} else {
    			curr->next = l2;
    			l2 = l2->next;
    			curr = curr->next;
    			curr->next = NULL;
    		}
    	}
    	if (!l1)
    		curr->next = l2;
    	if (!l2)
    		curr->next = l1;
    	ListNode *head = dummy->next;
    	free(dummy);
    	return head;
    }
};