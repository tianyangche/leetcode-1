#pragma once
#include <stddef.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class AddTwoNumbers
{
public:
	AddTwoNumbers(void);
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
	~AddTwoNumbers(void);
};

