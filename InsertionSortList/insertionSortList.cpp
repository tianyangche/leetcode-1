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
    ListNode *insertionSortList(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *node = head->next;
        if (!node)
            return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        newHead->next->next = NULL;
        while (node) {
            ListNode *curr = newHead;
            while (curr->next) {
                if (curr->next->val > node->val)
                    break;
                curr = curr->next;  
            }
            ListNode *temp = node;
            node = node->next;
            temp->next = curr->next;
            curr->next = temp;
        }
        ListNode *res = newHead->next;
        free(newHead);
        return res;
    }
};