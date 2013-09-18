#include "AddTwoNumbers.h"
#include <iostream>

using namespace std;

int main() {
	AddTwoNumbers addTwoNumbers;
	ListNode *a = new ListNode(1);
	ListNode *k = new ListNode(8);
	a->next =  k;
	ListNode *b = new ListNode(0);
	ListNode *listNode = addTwoNumbers.addTwoNumbers(a, b);
	while (listNode != NULL) {
		cout << listNode->val << endl;
		listNode = listNode->next;
	}
	system("pause");
}