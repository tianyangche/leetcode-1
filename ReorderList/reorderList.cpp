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
    void reorderList(ListNode *head) {
        if (!head)
        	return;
        vector<ListNode *> recs;
        while (head) {
        	recs.emplace_back(head);
        	head = head->next;
        }
        int i = 0;
        int j = recs.size() - 1;
        bool flag = false;
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        while (i <= j) {
        	if (!flag) {
        		node->next = recs[i];
        		i++;
        	} else {
        		node->next = recs[j];
        		j--;
        	}
        	node = node->next;
        	node->next = NULL;
        	flag = !flag;
        }
        free(dummy);
    }
}; 