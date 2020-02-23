#include<stdio.h>
#include<stdlib.h>
struct stackdll
{
 int data;
 struct stackdll *next;
 struct stackdll *prev;
};
typedef struct stackdll dlisted;
void check(dlisted *top,dlisted *rp)
{
	if(top==NULL && rp==NULL)
	{
		printf("Underflow\n\n");
		exit(1);
	}
}
void pus(dlisted **top,dlisted **rp,int value)
{
	dlisted *newnode;
	newnode=(dlisted*)malloc(sizeof(dlisted));
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
int popee(dlisted **top)
{
	int value=0;
	dlisted *temp;
	temp=(dlisted*)malloc(sizeof(dlisted));
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
void pee(dlisted **top,dlisted **rp)
{
	int value,flag=0,value2;
	printf("Enter value to peep from the stack:");
	scanf("%d",&value);
	dlisted *top1,*rp1;
	top1=(dlisted*)malloc(sizeof(dlisted));
	rp1=(dlisted*)malloc(sizeof(dlisted));
	top1=NULL;
	rp1=NULL;
	while(*top!=NULL)
	{
		if((*top)->data==value)
		{
			printf("%d is present in the stack & popped.\n\n",value);
			value2=popee(top);
			flag=1;
			break;
		}
		else
		{
			value2=popee(top);
			pus(&top1,&rp1,value2);
		}
	}
	while(top1!=NULL)
	{
		value2=popee(&top1);
		pus(top,rp,value2);
	}
	if(flag==0)
		printf("Element not found\n");
}
void trave(dlisted **top,dlisted **rp)
{
	int value2;
	dlisted *top1,*rp1;
	top1=(dlisted*)malloc(sizeof(dlisted));
	rp1=(dlisted*)malloc(sizeof(dlisted));
	top1=NULL;
	rp1=NULL;
  printf("The stack now is:\n");
	while(*top!=NULL)
	{
		printf("%d\n",(*top)->data);
		value2=popee(top);
		pus(&top1,&rp1,value2);
	}
	*top=NULL;
	*rp=NULL;
	while(top1!=NULL)
	{
		value2=popee(&top1);
		pus(top,rp,value2);
	}
}
void up(dlisted **top,dlisted **rp)
{
	int value,find=0,value2;
	printf("Enter value present in stack that you want to update :\n");
	scanf("%d",&value);
	dlisted *top1,*rp1;
	top1=(dlisted*)malloc(sizeof(dlisted));
	rp1=(dlisted*)malloc(sizeof(dlisted));
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
			value2=popee(top);
			pus(&top1,&rp1,value2);
		}
	}
	while(top1!=NULL)
	{
		value2=popee(&top1);
		pus(top,rp,value2);
	}

	if(find==0)
		printf("Element not found\n\n");
}
void stdll()
{
  char d,f;
	dlisted *top,*rp;
	top=(dlisted*)malloc(sizeof(dlisted));
	rp=(dlisted*)malloc(sizeof(dlisted));
	top=NULL;
	rp=NULL;
	int option,value;
  printf("\n********STACK USING DLL********");
	do {
    printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");

		printf("1.Push\n2. Pop\n3. Peep\n4. Traverse\n5. Update\n6.EXIT\n\n");
    printf("Enter your choice:\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
      do{
        printf("Enter the data to be inserted\n");
				scanf("%d",&value);
				pus(&top,&rp,value);
        trave(&top,&rp);
        printf("Want to enter more data?(Y/N)");
				scanf(" %c", &d);
      }while (d == 'Y' || d == 'y');
      printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
      break;
			case 2:
				check(top,rp);
				value=popee(&top);
				if(value!=0)
					printf("Element popped is %d\n",value);
          trave(&top,&rp);
      printf("Want to return to main menu?(Y/N)");
    	scanf(" %c", &f);
			break;
			case 3:
				check(top,rp);
				pee(&top,&rp);
        trave(&top,&rp);
        printf("Want to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
			case 4:
				check(top,rp);
				trave(&top,&rp);
        printf("Want to return to main menu?(Y/N)");
  			scanf(" %c", &f);
				break;
			case 5:
				check(top,rp);
				up(&top,&rp);
        trave(&top,&rp);
        printf("Want to return to main menu?(Y/N)");
  			scanf(" %c", &f);
				break;
			case 6:
				return;
        break;
			default:
      printf("Invalid input. Want to return to main menu?(Y/N)");
      scanf(" %c", &f);
      break;
		}
	}while(f=='y'||f=='Y');
}
