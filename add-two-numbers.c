#include <stdio.h>
#include <stdlib.h>
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){


	int carry = 0, x= 0, y = 0;
	struct ListNode *p = l1;
	struct ListNode *q = l2;
	int sum;
	struct ListNode *head = NULL;
	struct ListNode *current = NULL;

	head = (struct ListNode *) malloc(sizeof(struct ListNode));

	current = head;
	
	while (p != NULL || q != NULL) {

		int x = (p != NULL) ? p->val : 0;
		int y = (q != NULL) ? q->val : 0;
		sum = x + y + carry;
		carry = sum / 10;
		sum = sum % 10;
		printf("x:%d, y:%d, sum:%d, carry:%d\n", x,y,sum,carry);
		current->next = (struct ListNode *) malloc(sizeof(struct ListNode));
		current->next->val = sum;
		current->next->next = NULL;
		current = current->next;
		if (p != NULL)
			p = p->next;
		if(q != NULL)
			q = q->next;

		
	}
			

	return head->next;
		
	
}



int main()
{
	struct ListNode *l1 = NULL;
	struct ListNode *l2 = NULL;
	struct ListNode *l12 = NULL;
	struct ListNode *l13 = NULL;
	struct ListNode *l22 = NULL;
	struct ListNode *l23 = NULL;

	struct ListNode *ret;

	l1 = (struct ListNode *) malloc (sizeof(struct ListNode));
	l2 = (struct ListNode *) malloc (sizeof(struct ListNode));
	l12 = (struct ListNode *) malloc (sizeof(struct ListNode));
	l13 = (struct ListNode *) malloc (sizeof(struct ListNode));
	l22 = (struct ListNode *) malloc (sizeof(struct ListNode));
	l23 = (struct ListNode *) malloc (sizeof(struct ListNode));

	l1->val = 2;
	l1->next = l12;
	l12->val = 4;
	l12->next = l13;
	l13->val = 3;
	l13->next = NULL;

	l2->val = 5;
	l2->next = l22;
	l22->val = 6;
	l22->next = l23;
	l23->val = 4;
	l23->next = NULL;


	ret = addTwoNumbers(l1, l2);

	printf("Ret %d %d %d\n", ret->val, ret->next->val, ret->next->next->val);

 }
