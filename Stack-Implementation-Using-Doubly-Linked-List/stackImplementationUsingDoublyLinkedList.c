#include<stdio.h>
#include<stdlib.h>
struct stackdll
{
 int data;
 struct stackdll *next;
 struct stackdll *prev;
};
typedef struct stackdll dlist;

void check(dlist *top,dlist *rp)
{
	if(top==NULL && rp==NULL)
	{
		printf("Underflow\n\n");
		exit(1);
	}
}
void push(dlist **top,dlist **rp,int value)
{
	dlist *newnode;
	newnode=(dlist*)malloc(sizeof(dlist));
	newnode->data=value;
	if(*top==NULL && *rp==NULL)
	{
		newnode->prev='\0';
		newnode->next='\0';
		*top=newnode;
		*rp=newnode;
	}
	else
	{
		newnode->prev='\0';
		newnode->next=*top;
		(*top)->prev=newnode;
		(*top)=newnode;
	}
}
int pop(dlist **top)
{
	int value=0;
	dlist *temp;
	temp=(dlist*)malloc(sizeof(dlist));
	if((*top)!=NULL)
	{
		value=(*top)->data;
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
	else
		printf("Underflow\n\n");
	return value;
}
void peep(dlist **top,dlist **rp)
{
	int value,flag=0,value2;
	printf("Enter value to peep from the stack:");
	scanf("%d",&value);
	dlist *top1,*rp1;
	top1=(dlist*)malloc(sizeof(dlist));
	rp1=(dlist*)malloc(sizeof(dlist));
	top1=NULL;
	rp1=NULL;
	while(*top!=NULL)
	{
		if((*top)->data==value)
		{
			printf("%d is present in the stack & popped.\n\n",value);
			value2=pop(top);
			flag=1;
			break;
		}
		else
		{
			value2=pop(top);
			push(&top1,&rp1,value2);
		}
	}
	while(top1!=NULL)
	{
		value2=pop(&top1);
		push(top,rp,value2);
	}
	if(flag==0)
		printf("Element not found\n");
}
void traverse(dlist **top,dlist **rp)
{
	int value2;
	dlist *top1,*rp1;
	top1=(dlist*)malloc(sizeof(dlist));
	rp1=(dlist*)malloc(sizeof(dlist));
	top1=NULL;
	rp1=NULL;
  printf("The stack now is:\n");
	while(*top!=NULL)
	{
		printf("%d\n",(*top)->data);
		value2=pop(top);
		push(&top1,&rp1,value2);
	}
	*top=NULL;
	*rp=NULL;
	while(top1!=NULL)
	{
		value2=pop(&top1);
		push(top,rp,value2);
	}
}
void update(dlist **top,dlist **rp)
{
	int value,find=0,value2;
	printf("Enter value present in stack that you want to update :\n");
	scanf("%d",&value);
	dlist *top1,*rp1;
	top1=(dlist*)malloc(sizeof(dlist));
	rp1=(dlist*)malloc(sizeof(dlist));
	top1=NULL;
	rp1=NULL;
	while(*top!=NULL)
	{
		if((*top)->data==value)
		{
			printf("Enter a new value");
			scanf("%d",&(*top)->data);
			find=1;
			break;
		}
		else
		{
			value2=pop(top);
			push(&top1,&rp1,value2);
		}
	}
	while(top1!=NULL)
	{
		value2=pop(&top1);
		push(top,rp,value2);
	}

	if(find==0)
		printf("Element not found\n\n");
}
int main()
{

  printf("******* STACK USING DATA STRUCTURE: DOUBLY LINKED LIST *******\n");
  char d,f;
	dlist *top,*rp;
	top=(dlist*)malloc(sizeof(dlist));
	rp=(dlist*)malloc(sizeof(dlist));
	top=NULL;
	rp=NULL;
	int option,value;
	do {

    printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");
		printf("1. Push\n2. Pop\n3. Peep\n4. Traverse\n5. Update\n6. Exit");
    printf("\nEnter your choice:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
      do{
        printf("Enter the data to be inserted\n");
				scanf("%d",&value);
				push(&top,&rp,value);
        traverse(&top,&rp);
        printf("Want to enter more data?(Y/N)");
				scanf(" %c", &d);
      }while (d == 'Y' || d == 'y');
      printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
      break;
			case 2:
				check(top,rp);
				value=pop(&top);
				if(value!=0)
					printf("Element popped is %d\n",value);
          traverse(&top,&rp);
      printf("Want to return to main menu?(Y/N)");
    	scanf(" %c", &f);
			break;
			case 3:
				check(top,rp);
				peep(&top,&rp);
        traverse(&top,&rp);
        printf("Want to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
			case 4:
				check(top,rp);
				traverse(&top,&rp);
        printf("Want to return to main menu?(Y/N)");
  			scanf(" %c", &f);
				break;
			case 5:
				check(top,rp);
				update(&top,&rp);
        traverse(&top,&rp);
        printf("Want to return to main menu?(Y/N)");
  			scanf(" %c", &f);
				break;
			case 6:
				exit(1);
			default:
      printf("Invalid input. Want to return to main menu?(Y/N)");
      scanf(" %c", &f);
		}
	}while(f=='y'||f=='Y');
	return 0;
}
