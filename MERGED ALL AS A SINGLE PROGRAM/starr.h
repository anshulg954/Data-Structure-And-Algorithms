#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int A[MAX]; //STACKDEFINE
int top; //TOP POINTER OF STACK
int SS[MAX]; //SUPPLEMENTARY STACK
int tops=-1; //TOP POINTER OF SUPPLEMENTARY STACK
//PUSH FUNC
void Push(int x){
	if (top == MAX) {
		printf("OVERFLOW , stack is full so cant add more elements\n");
		return;
	}
	A[++top] = x;
	return;
}
//POP FUNC
int Pop(){
	int x;
	if (top == -1) {
		printf("UNDERFLOW AND EXIT\n");
		exit(0);
	}
	x=A[top];
	printf("The element to be deleted is:%d\n", A[top]);
	top--;
	return x;
}
//PRINT FUNC USING SUPPLEMENTARY STACK
void traversal(){
	int temp = top;
	if (top == -1) {
		printf("Stack is empty");
		return;
	}
	else
        while (temp != -1) {
            tops++;
            printf("%d\n", A[temp]);
            SS[tops]=A[temp];
            temp--;
        }
        while (tops != -1) {
            temp++;
            A[temp]=SS[tops];
            tops--;
        }
	return;
}
//PEEP FUNC USING SUPPLEMENTARY STACK
void peep(int value){
	if (top == -1) {
		printf("Stack is empty");
		return;
	}
	while (top != -1 && value!=A[top]){
		SS[++tops] = A[top--];
	}
	printf("The data %d is found at location %d\n",A[top],top);
	Pop();
	while (tops != -1){
		 A[++top]=SS[tops--];
	}
	printf("The stack after deletion of found value is as follows\n");
	traversal();
	return;
}
//UPDATE FUNC USING SUPPLEMENTARY STACK
void updat(int value){
	int key;
    printf("Enter Key to update\n");
    scanf("%d",&key);
	if (top == -1) {
		printf("Stack is empty");
		return;
	}
	else
        while (top != -1 && value!=A[top]){
            SS[++tops] = A[top--];
        }
        printf("The data %d is found at location %d\n",A[top],top);
        A[top]=key;
        while (tops != -1){
             A[++top]=SS[tops--];
        }
	printf("The stack after updation of found value is as follows\n");
	traversal();
	return;
}
//MAIN FUNC
void starr()
{
	top = -1;
	int c;
	char f;
	int x;
    char d;
    int pos;
    int popped;
		printf("\n******** STACK USING ARRAY ********");
	do
	{
		printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");

	printf("\t 1.Push an element.\n");
	printf("\t 2.Pop an element.\n");
	printf("\t 3.Print stack.\n");
	printf("\t 4.Peep at desired location.\n");
	printf("\t 5.Update.\n");
	printf("\t 6.EXIT\n");
	printf("\nEnter your choice:\n");
	scanf("%d", &c);
	switch (c) {
	case 1:
		do{
			printf("Enter the data to be inserted\n");
			scanf(" %d", &x);
			Push(x);
			printf("The stack after addition of new element is as follows\n");
			traversal();
			printf("Want to enter more data?(Y/N)");
			scanf(" %c", &d);
		}while (d == 'Y' || d == 'y');
		printf("Want to return to main menu?(Y/N)");
		scanf(" %c", &f);
		break;
	case 2:
		printf("The stack is as follows:\n");
		traversal();
		char y;
		printf("Do you want to pop an element?(Y/N)");
		scanf(" %c", &y);
		if (y == 'Y' || y == 'y')
			popped=Pop();
		printf("Want to return to main menu?(Y/N)");
		scanf(" %c", &f);
		break;
	case 3:
		printf("The stack is as follows:\n");
		traversal();
		printf("Want to return to main menu?(Y/N)");
		scanf(" %c", &f);
		break;
	case 4:
		printf("Enter the value of element whose info you want to peep\n");
		scanf(" %d", &pos);
		peep(pos);
		printf("Want to return to main menu?(Y/N)");
		scanf(" %c", &f);
		break;
	case 5:
	  printf("Enter the value of element whose info you want to update\n");
		scanf(" %d", &pos);
		updat(pos);
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
	} while (f=='Y'||f=='y');
}
