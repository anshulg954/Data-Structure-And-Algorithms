#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char name[32];
    int sem;
    char branch[32];
    char roll_no[7];
struct student* prev;
struct student* next;
}*head=NULL,*last=NULL;
typedef struct student dlist;
void creating()
{
    int n,i;
    dlist* newnode;
    printf("Enter the number of records you want to enter\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        newnode=(dlist*)malloc(sizeof(struct student));
        printf("Enter the name of student %d:",i);
        fflush(stdin);
        gets(newnode->name);
        printf("Enter the semester of student %d(1/2/3/4/5/6/7/8):",i);
        scanf("%d",&(newnode->sem));
        printf("Enter the branch of student %d:",i);
        fflush(stdin);
        gets(newnode->branch);
        fflush(stdin);
        printf("Enter the roll number of student %d:",i);
        gets(newnode->roll_no);
        fflush(stdin);
        if(head==NULL)
        {
            head=(dlist*)malloc(sizeof(struct student));
            head=newnode;
            head->next=NULL;
            head->prev=NULL;
            last=head;
        }
        else{
            last->next=newnode;
            newnode->next=NULL;
            newnode->prev=last;
            last=last->next;
        }
    }
}
void inserting()
{
    dlist* newnode,*ptr,*temp;
    newnode=(dlist*)malloc(sizeof(struct student));
    int position,i;
    printf("Enter the position at which you want to insert\n");
    scanf("%d",&position);
        printf("Enter the name of student: ");
        fflush(stdin);
        gets(newnode->name);
        printf("Enter the semester of student(1/2/3/4/5/6/7/8): ");
        scanf("%d",&(newnode->sem));
        printf("Enter the branch of student: ");
        fflush(stdin);
        gets(newnode->branch);
        printf("Enter the roll number of student: ");
        fflush(stdin);
        gets(newnode->roll_no);
        fflush(stdin);
    if(position==1){

        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
    }
        temp=head;
    if(position>1){
        printf("Entering data\n");
        for(i=1;i<position-1;i++)
        {
            temp=temp->next;
        }
        ptr=head;
        for(i=1;i<position;i++)
        {
            ptr=ptr->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;

        if(temp->next!=NULL)
        {
            temp->next=ptr;
            ptr->prev=temp;
        }
        else
            last=temp;
      }
}
void searching()
{
    dlist* temp;
    char rollno[7];
    int flag;
    printf("Enter the rollno of student you want to search:\n");
    fflush(stdin);
    gets(rollno);
    temp=head;
    while(temp!=NULL)
    {
        if(strcmp(rollno,temp->roll_no)==0)
        {
            printf("Roll No: %s\t",temp->roll_no);
              printf("Name: %s\t",temp->name);
              printf("Semester: %d\t",temp->sem);
              printf("Branch: %s\t",temp->branch);
            flag++;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("Record not found");
    }
    else
      printf("Record found\n");
}
void traversing()
{
    int choice,i=1;
    dlist* temp;
    printf("1.Forward OR 2.Backward\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        temp=head;
         printf("\tRoll no.\t\t Name\t\t Branch\t\tSemester\t\n");
        while(temp!=NULL)
        {

            printf("\n\t %s\t\t%s\t\t%s\t\t%d ",temp->roll_no,temp->name,temp->branch,temp->sem);
			temp=temp->next;
            i++;
        }
        break;
    case 2:
        temp=last;
         printf("\tRoll no.\t\t Name\t\t Branch\t\tSemester\t\n");
        while(temp!=NULL)
        {
            printf("\n\t %s\t\t%s\t\t%s\t\t%d ",temp->roll_no,temp->name,temp->branch,temp->sem);
            temp=temp->prev;
        }
        break;
    }
}
void deleting()
{
    dlist* temp;
    char rollno[7];
    printf("Enter the rollno of student you want to delete: \n");
    fflush(stdin);
    gets(rollno);
    temp=head;
    while(temp!=NULL)
    {if(strcmp(rollno,temp->roll_no)!=0){temp=temp->next;}
    else break;
    }
    if(temp==head){
            head=head->next;
            head->prev=NULL;
            free(temp);
    }
    else if(temp==last){
            temp->prev->next=NULL;
            last=temp->prev;
            free(temp);
  }
   else if(temp==NULL) {
        printf("%s record does not exist",rollno);
        return ;
    }
    else {
                   temp->prev->next=temp->next;
                   temp->next->prev=temp->prev;
                   free(temp);
    }
}
void updating()
{
    dlist* temp,*newnode;
    newnode=(dlist*)malloc(sizeof(struct student));
    char rollno[7];
    int flag;
    temp=head;
    printf("Enter the roll no you want to update\n");
    fflush(stdin);
    gets(rollno);
    while(temp!=NULL)
    {
        if(strcmp(rollno,temp->roll_no)==0)
        {
        printf("Enter the updated name of student: ");
        gets(temp->name);
        printf("Enter the updated semester of student: ");
        fflush(stdin);
        scanf("%d",&(temp->sem));
        printf("Enter the updated branch of student: ");
        fflush(stdin);
        gets(temp->branch);
        printf("Enter the updated roll number of student: ");
        fflush(stdin);
        gets(temp->roll_no);
                flag++;
                break;
       }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("Record not found\n");
    }
    else
      printf("Record updated!!\n");
}
void reporting()
{
  dlist* temp;
  char branch[32];
  int choice,count,sem;
  printf("1.Report based on semester\n2.Report based on branch.\n");
  printf("Enter your choice:\n");
  scanf("%d",&choice);
switch (choice){
  case 1:
  printf("Enter the semester you want to get the report of(1/2/3/4/5/6/7/8):\n");
  scanf("%d",&sem);
  temp=head;
  while(temp!=NULL)
  {
      if(sem==temp->sem)
      {
        printf("Roll No: %s\t",temp->roll_no);
        printf("Name: %s\t",temp->name);
        printf("Semester: %d\t",temp->sem);
        printf("Branch: %s\t",temp->branch);
        printf("\n");
          count++;
      }
      temp=temp->next;
  }
  printf("The number of students in semester %d is %d\n",sem,count);
  if(count==0){
      printf("No students found");
  }
  break;
  case 2:
  printf("Enter the branch you want to get the report of:\n");
  fflush(stdin);
  gets(branch);
  temp=head;
  while(temp!=NULL)
  {
      if(strcmp(branch,temp->branch)==0)
      {
          printf("Roll No: %s\t",temp->roll_no);
          printf("Name: %s\t",temp->name);
          printf("Semester: %d\t",temp->sem);
          printf("Branch: %s\t",temp->branch);
          printf("\n");
          count++;
      }
      temp=temp->next;
    }
  printf("The number of students in branch %s is %d\n",branch,count);
  if(count==0)
  {
      printf("No students found\n");
  }
  break;
  default:
  printf("Wrong Input\n");
  break;
}
}
void stdrecdll()
{
    int choice;
    char f;
  printf("\n********STUDENT RECORD USING DLL********");
do{
  printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");

    printf("1.Create List.\n");
    printf("2.Insert a record.\n");
    printf("3.Search a record.\n");
    printf("4.Traverse.\n");
    printf("5.Delete a record.\n");
    printf("6.Update a record.\n");
    printf("7.Report generation\n");
    printf("8.EXIT\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
   switch(choice){
    case 1:
        creating();
        printf("\nWant to return to main menu?(Y/N)");
    		scanf(" %c", &f);
        break;
    case 2:
        inserting();
        printf("\nWant to return to main menu?(Y/N)");
    		scanf(" %c", &f);
        break;
    case 3:
        searching();
        printf("\nWant to return to main menu?(Y/N)");
    		scanf(" %c", &f);
        break;
    case 4:
         traversing();
         printf("\nWant to return to main menu?(Y/N)");
     		scanf(" %c", &f);
         break;
    case 5:
        deleting();
        printf("\nWant to return to main menu?(Y/N)");
    		scanf(" %c", &f);
        break;
    case 6:
        updating();
        printf("\nWant to return to main menu?(Y/N)");
        scanf(" %c", &f);
        break;
    case 7:
    reporting();
    printf("\nWant to return to main menu?(Y/N)");
    scanf(" %c", &f);
    break;
    case 8:
        return;
        break;
    default:
        printf("\nEnter a valid choice");
        printf("\nWant to return to main menu?(Y/N)");
    		scanf(" %c", &f);
        break;
    }}while(f=='y'||f=='Y');
}
