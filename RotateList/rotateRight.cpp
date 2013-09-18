struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
        	return head;
        int len = getListLength(head);
        if (len == 1 || len == k)
        	return head;
        k = k % len;
        ListNode * node1 = head;
        ListNode * node2 = head;
        int step = 0;
        while (node2->next != NULL) {
        	if (step < k) {
        		node2 = node2->next;
        	} else {
        		node1 = node1->next;
        		node2 = node2->next;
        	}
        	step++;
        }
        node2->next = head;
        ListNode * res = node1->next;
        node1->next = NULL;
        return res;
    }

    int getListLength(ListNode * head) {
    	int len = 0;
    	while (head != NULL) {
    		head = head->next;
    		len++;
    	}
    	return len;
    }
};