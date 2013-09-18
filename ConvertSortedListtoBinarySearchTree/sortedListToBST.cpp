/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        int size = listSize(head);
        TreeNode * treeNode = (TreeNode *)malloc(sizeof(struct TreeNode));
        treeNode->left  = NULL;
        treeNode->right = NULL;
        convert(treeNode, head, size);
        return treeNode;
    }

    int listSize(ListNode *head) {
    	int size = 0;
  		ListNode * node = head;
    	while (node != NULL) {
    		size++;
    		node = node->next;
    	}
    	return size;
    }

    void convert(TreeNode *treeNode, ListNode *listNode, int size) {
    	if (size == 1) {
    		treeNode->val = listNode->val;
    	} else {
    		int halfSize = 0;
    		if (size % 2 == 0)
    			halfSize = size / 2;
    		else
    			halfSize = size / 2 + 1;
    		ListNode * midNode = (ListNode *)malloc(sizeof(struct ListNode));
        	findMid(listNode, halfSize, midNode);
    		treeNode->val = midNode->val;
    		if (halfSize > 1) {
    			TreeNode * leftNode = (TreeNode *)malloc(sizeof(struct TreeNode));
    			leftNode->left = NULL;
    			leftNode->right = NULL;
    			treeNode->left = leftNode;
    			convert(leftNode, listNode, halfSize-1);
    		}
    		if (size - halfSize > 0) {
    			TreeNode * rightNode = (TreeNode *)malloc(sizeof(struct TreeNode));
    			rightNode->left = NULL;
    			rightNode->right = NULL;
    			treeNode->right = rightNode;
    			convert(rightNode, midNode->next, size-halfSize);
    		}
    	}
    }

    void findMid(ListNode * headNode, int halfSize, ListNode * midNode) {
        int i = 1;
    	ListNode * listNode = headNode;
    	while (i < halfSize) {
    		i++;
    		listNode = listNode->next;
    	}
    	midNode->val = listNode->val;
    	midNode->next = listNode->next;
    }
};