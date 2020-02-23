#include <stdio.h>
#include <stdlib.h>
struct record {
	int data;
	struct record* next;
};
typedef struct record listed;
void pushing(listed** head, int n)
{
	listed* new_node;
	new_node = (listed*)malloc(sizeof(listed));
	new_node->data = n;
	new_node->next = (*head);
	(*head) = new_node;
}
void popping(listed** head)
{
	printf("The data to be deleted is %d \n", (*head)->data);
	listed* temp;
	temp = (*head);
	(*head) = (*head)->next;
    free(temp);
}
void trav(listed** head) {
	listed* headS = NULL;
	if ((*head) == NULL)
	{
		printf("UNDERFLOW, stack is empty, exiting");
		exit(0);
	}
	else{
	while (*head)
	{
			listed* temp;
			temp = (*head);
			printf("%d\n",temp->data);
			pushing(&headS, (*head)->data);
			(*head) = (*head)->next;
			free(temp);
	}
	while (headS) {
			pushing(&(*head), (headS)->data);
			listed* temp;
			temp = headS;
			(headS) = (headS)->next;
			free(temp);
		}
	}
}
void peeping(listed** head, int element) {
	if ((*head) == NULL)
	{
		printf("UNDERFLOW, stack is empty, exiting");
		exit(0);
	}
	int flag = 0;
	listed* headS = NULL;
	while ((*head) && flag != 1)
	{
		if ((*head)->data == element)
		{
			printf("Element found in stack and popped.\n");
			flag = 1;
		  popping(&(*head));
		}
		else
		{
			pushing(&headS, (*head)->data);
			listed* temp;
			temp = (*head);
			(*head) = (*head)->next;
			free(temp);
		}
	}
	while ((headS))
	{
		pushing(&(*head), headS->data);
		listed* temp;
		temp = (headS);
		(headS) = (headS)->next;
		free(temp);
	}
	if(flag==0)
	   printf("Element NOT FOUND\n");
}

void upda(listed** head, int element) {
	int key;
	int flag = 0;
	listed* headS = NULL;
	if ((*head) == NULL)
	{
		printf("UNDERFLOW, stack is empty, exiting");
		exit(0);
	}
	printf("Enter key to upda:\n");
	scanf("%d",&key);
	while (*head)
	{
		if ((*head)->data == element)
		{
			flag=1;
			printf("Element found in stack & updated.\n");
			(*head)->data=key;
		}
		pushing(&headS, (*head)->data);
		(*head) = (*head)->next;
	}
	while ((headS))
	{
		pushing(&(*head), headS->data);
		listed* temp;
		temp = (headS);
		(headS) = (headS)->next;
		free(temp);
	}
	if(flag==0)
	   printf("Element NOT FOUND\n");
}
void stll()
{
	listed* start;
	start = NULL;
	int c,x,pos;
	char d,f;
  printf("\n******** STACK USING SLL ********");
	do
	{
		printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");
		printf("\t 1.Push an element.\n");
		printf("\t 2.Pop an element.\n");
		printf("\t 3.Traverse stack.\n");
		printf("\t 4.Peep a desired element.\n");
		printf("\t 5.UPDATE.\n");
		printf("\t 6.EXIT\n");
		printf("\nEnter your choice: ");
		scanf("%d", &c);
		switch (c) {
		case 1:
			do {
				printf("Enter the data to be inserted\n");
				scanf(" %d", &x);
				pushing(&start, x);
				printf("The stack after addition of new element is as follows\n");
				trav(&start);
				printf("Want to enter more data?(Y/N)");
				scanf(" %c", &d);
			}while (d == 'Y' || d == 'y');
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 2:
			printf("The stack is as follows:\n");
			trav(&start);
			char y;
			printf("Do you want to pop an element?(Y/N)");
			scanf(" %c", &y);
			if (y == 'Y' || y == 'y')
				popping(&start);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 3:
		printf("The Stack is as follows:\n");
		trav(&start);
		printf("Want to return to main menu?(Y/N)");
		scanf(" %c", &f);
		break;
		case 4:
			printf("Enter the element which you want to peep in stack\n");
			scanf(" %d", &pos);
			peeping(&start, pos);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 5:
			printf("Enter the element which you want to update in stack\n");
			scanf(" %d", &pos);
			upda(&start, pos);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 6:
			return;
			break;
		default:
			printf("Invalid Choice, re-enter choice.");
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		}
	} while (f == 'Y' || f == 'y');
}
