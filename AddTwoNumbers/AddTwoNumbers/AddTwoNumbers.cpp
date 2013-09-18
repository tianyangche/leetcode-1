#include "AddTwoNumbers.h"

AddTwoNumbers::AddTwoNumbers(void)
{
}

ListNode *AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2) {
	
	ListNode *headNode = NULL;
	headNode = new ListNode(0);
	ListNode *node = headNode;
	while (l1 != NULL && l2 != NULL) {
		node->val += l1->val + l2->val;
		if (node->val >= 10) {
			ListNode *newNode = new ListNode(node->val/10);
			node->val = node->val % 10;
			node->next = newNode;
			node = node->next;
		} else
			if (l1->next != NULL || l2->next != NULL) {
				ListNode *newNode = new ListNode(0);
				node->next = newNode;
				node = node->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	
	while (l1 != NULL) {
		node->val += l1->val;
		if (node->val >= 10) {
			ListNode *newNode = new ListNode(node->val/10);
			node->val = node->val % 10;
			node->next = newNode;
			node = node->next;
		} else
			if (l1->next != NULL) {
				ListNode *newNode = new ListNode(0);
				node->next = newNode;
				node = node->next;
		}
		l1 = l1->next;
	}
	while (l2 != NULL) {
		node->val += l2->val;
		if (node->val >= 10) {
			ListNode *newNode = new ListNode(node->val/10);
			node->val = node->val % 10;
			node->next = newNode;
			node = node->next;
		} else
			if (l2->next != NULL) {
				ListNode *newNode = new ListNode(0);
				node->next = newNode;
				node = node->next;
		}
		l2 = l2->next;
	}
	return headNode;
}

AddTwoNumbers::~AddTwoNumbers(void)
{
}
