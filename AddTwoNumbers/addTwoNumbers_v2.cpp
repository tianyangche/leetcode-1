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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
        	return l2;
        if (l2 == NULL)
        	return l1;
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        head->next = NULL;
        ListNode *res  = head;
        int temp = 0;
        while (l1 != NULL && l2 != NULL) {
        	temp += l1->val + l2->val;
        	ListNode *n3 = (ListNode *)malloc(sizeof(ListNode));
        	n3->val   = temp % 10;
        	n3->next  = NULL;
        	res->next = n3;
        	res = res->next;
        	temp /= 10;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        compList(l1, &res, temp);
        compList(l2, &res, temp);
        while (temp > 0) {
        	ListNode *n3 = (ListNode *)malloc(sizeof(ListNode));
        	n3->val   = temp % 10;
   			n3->next  = NULL;
        	res->next = n3;
        	res = res->next;
        	temp /= 10;
        }
        res = head->next;
        free(head);
        return res;
    }

    void compList(ListNode *node, ListNode **res, int &temp) {
    	while (node != NULL) {
        	temp += node->val;
        	ListNode *n3 = (ListNode *)malloc(sizeof(ListNode));
        	n3->val   = temp % 10;
        	n3->next  = NULL;
        	(*res)->next = n3;
        	*res = (*res)->next;
        	temp /= 10;
        	node = node->next;
        }
    }
};