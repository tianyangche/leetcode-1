/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
        	return NULL;
        map<int, RandomListNode*> recs;
        return copyRandomList(head, recs);
    }

    RandomListNode *copyRandomList(RandomListNode *head, map<int, RandomListNode*> &recs) {
    	if (head == NULL)
    		return NULL;
    	if (recs.count(head->label) > 0)
    		return recs[head->label];
    	RandomListNode *node = new RandomListNode(head->label);
    	recs[head->label] = node;
    	if (head->next != NULL) {
    		node->next = copyRandomList(head->next, recs);
    	}
    	if (head->random != NULL) {
    		node->random = copyRandomList(head->random, recs);
    	}
    	return node;
    }
};