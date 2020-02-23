#include <stdio.h>
#include <stdlib.h>
struct record {
	int data;
	struct record* next;
};
typedef struct record list;
void push(list** head, int n)
{
	list* new_node;
	new_node = (list*)malloc(sizeof(list));
	new_node->data = n;
	new_node->next = (*head);
	(*head) = new_node;
}
void stack_reverse(list **head, list **head_next)
{
    list *temp;
    if (*head_next != NULL)
    {
         temp = (*head_next)->next;
        (*head_next)->next = (*head);
        *head = *head_next;
        *head_next = temp;
        stack_reverse(head, head_next);
    }
}
void pop(list** head)
{
	printf("The data to be deleted is %d \n", (*head)->data);
	list* temp;
	temp = (*head);
	(*head) = (*head)->next;
    free(temp);
}
void traverse(list** head) {
	list* headS = NULL;
	if ((*head) == NULL)
	{
		printf("UNDERFLOW, stack is empty, exiting");
		exit(0);
	}
	else{
	while (*head)
	{
			list* temp;
			temp = (*head);
			printf("%d\n",temp->data);
			push(&headS, (*head)->data);
			(*head) = (*head)->next;
			free(temp);
	}
	while (headS) {
			push(&(*head), (headS)->data);
			list* temp;
			temp = headS;
			(headS) = (headS)->next;
			free(temp);
		}
	}
}
void peep(list** head, int element) {
	if ((*head) == NULL)
	{
		printf("UNDERFLOW, stack is empty, exiting");
		exit(0);
	}
	int flag = 0;
	list* headS = NULL;
	while (*head)
	{
		if ((*head)->data == element)
		{
			printf("Element found in stack and peeped.\n");
			flag = 1;
			list* temp = (*head);
			(*head) = (*head)->next;
			free(temp);
		}
		else
		{
			push(&headS, (*head)->data);
			list *temp=*head;
			(*head) = (*head)->next;
			free(temp);
		}
	}
	while (headS)
	{
		push(&(*head), headS->data);
		list *temp=headS;
		(headS) = (headS)->next;
		free(temp);
	}
	if(flag==0)
	   printf("Element NOT FOUND\n");
}

void update(list** head, int element) {
	int key;
	int flag = 0;
	list* headS = NULL;
	if ((*head) == NULL)
	{
		printf("UNDERFLOW, stack is empty, exiting");
		exit(0);
	}
	printf("Enter key to update:\n");
	scanf("%d",&key);
	while (*head)
	{
		if ((*head)->data == element)
		{
			flag=1;
			printf("Element found in stack & updated.\n");
			(*head)->data=key;
		}
		push(&headS, (*head)->data);
		(*head) = (*head)->next;
	}
	while ((headS))
	{
		push(&(*head), headS->data);
		list* temp;
		temp = (headS);
		(headS) = (headS)->next;
		free(temp);
	}
	if(flag==0)
	   printf("Element NOT FOUND\n");
}
int main()
{

	printf("******* STACK USING DATA STRUCTURE: SINGLY LINKED LIST *******\n");
	list* start;
	start = NULL;
	int c,x,pos;
	char d,f;
	do
	{

		printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");
		printf("\t 1.Push an element.\n");
		printf("\t 2.Pop an element.\n");
		printf("\t 3.Traverse stack.\n");
		printf("\t 4.Peep a desired element.\n");
		printf("\t 5.UPDATE.\n");
		printf("\t 6.Reverse.");
		printf("\nEnter your choice:");
		scanf("%d", &c);
		switch (c) {
		case 1:
			do {
				printf("Enter the data to be inserted\n");
				scanf(" %d", &x);
				push(&start, x);
				printf("The stack after addition of new element is as follows\n");
				traverse(&start);
				printf("Want to enter more data?(Y/N)");
				scanf(" %c", &d);
			}while (d == 'Y' || d == 'y');
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 2:
			printf("The stack is as follows:\n");
			traverse(&start);
			char y;
			printf("Do you want to pop an element?(Y/N)");
			scanf(" %c", &y);
			if (y == 'Y' || y == 'y')
				pop(&start);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 3:
		printf("The Stack is as follows:\n");
		traverse(&start);
		printf("Want to return to main menu?(Y/N)");
		scanf(" %c", &f);
		break;
		case 4:
			printf("Enter the element which you want to peep in stack\n");
			scanf(" %d", &pos);
			peep(&start, pos);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 5:
			printf("Enter the element which you want to update in stack\n");
			scanf(" %d", &pos);
			update(&start, pos);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 6:
			stack_reverse(&start,&(start->next));
			printf("The Stack is as follows:\n");
			traverse(&start);
			break;
		default:
			printf("Invalid Choice, re-enter choice.");
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		}
	} while (f == 'Y' || f == 'y');
	return 0;
}
