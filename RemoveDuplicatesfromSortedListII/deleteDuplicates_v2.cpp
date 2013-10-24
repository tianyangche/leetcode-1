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
        if (!head)
        	return NULL;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        int currVal = head->val;
        ListNode **node = &(dummyNode->next);
        bool flag = false;
        while ((*node)->next) {
        	if ((*node)->val == (*node)->next->val) {
        		ListNode *delNode = (*node)->next;
        		(*node)->next = (*node)->next->next;
        		free(delNode);
        		flag = true;
        	} else {
        		if (flag) {
        			ListNode *delNode = *node;
        			*node = (*node)->next;
        			free(delNode);
        		} else {
        			node = &((*node)->next);
        		}
        		flag = false;
        	}
        }
        if (flag) {
        	ListNode *delNode = *node;
        	*node = (*node)->next;
        	free(delNode);
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};