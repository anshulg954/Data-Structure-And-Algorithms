#include<stdio.h>
#include<malloc.h>
typedef struct record{
	int priority;
	int info;
	struct record *next;
};
typedef struct record list;
list *start = NULL;
	list *temp;
//TO INSERT BASED ON PRIORITY IN DESCENDING ORDER
void push(int value,int priority)
{
	list *q;
	temp =(list*)malloc(sizeof(list));
	temp->info = value;
	temp->priority = priority;
	if(start == NULL || priority > start->priority)
	{
		temp->next = start;
		start = temp;
	}
	else
	{
		q = start;
        while(q->next != NULL && q->next->priority >= priority )
            q=q->next;
            temp->next = q->next;
            q->next = temp;
	}
}
//TO DELETE ELEMENT WITH TOPMOST PRIORITY
void pop()
{
	if(start == NULL)
		printf("Queue Underflow\n");
	else
	{
		temp = start;
		printf("Deleted item is %d\n",temp->info);
		start = start->next;
		free(temp);
	}
}
//TO PRINT THE QUEUE.
void display()
{
	list *ptr;
	ptr = start;
	if(start == NULL)
		printf("Queue is empty\n");
	else
	{
		printf("Queue is :\n");
		printf("Priority    --   Value\n");
		while(ptr != NULL)
		{
			printf("%5d        %5d\n",ptr->priority,ptr->info);
			ptr = ptr->next;
		}
	}
}
void update(int value){
	int flag=0;
		list *ptr;
		ptr = start;
		if(start == NULL)
			printf("Queue is empty\n");
		else
				while (ptr!=NULL) {
					if(ptr->info==value){
						printf("Enter updated priority\n");
						scanf("%d",&(ptr->priority));
					flag=1;
					}
				ptr=ptr->next;
			}
	if(flag==0){
		printf("Element Not found");
	}
}
//MAINFUNC
int main()
{

	printf("******* PRIORITY QUEUE *******\n");
	int choice,value,priority,f;
	do
	{
		printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");
		printf("1.Insert(PUSH)\n");
		printf("2.Delete(POP)\n");
		printf("3.Display(TRAVERSE)\n");
		printf("4.Update\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Input the value of the element to be added in the queue : ");
				scanf("%d",&value);
				printf("Enter its priority : ");
				scanf("%d",&priority);
				push(value,priority);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
        case 4:
				 printf("Enter value whose priority you want to update\n");
				 scanf("%d",&value );
			   update(value);
				 display();
         break;
      default :
				printf("Wrong choice\n");
				break;
		}
	}while(choice!=5);
	return 0;
}
