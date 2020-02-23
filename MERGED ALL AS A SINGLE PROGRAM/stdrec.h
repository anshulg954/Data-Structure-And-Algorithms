#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct recd
{
  char name[32];
  char branch[32];
  char roll_no[7];
  int semester;
};
typedef struct recd stud;
static int num = 0;
static int maxCount = 0;
void input(stud *data)
{
  if(maxCount < num)
  {
    printf("Enter Name :");
    fflush(stdin);
    gets(data[maxCount].name);
    printf("Enter Branch : ");
    fflush(stdin);
    gets(data[maxCount].branch);
    printf("Enter Roll no : ");
    fflush(stdin);
    gets(data[maxCount].roll_no);
    printf("Enter Semester(1/2/3/4/5/6/7/8) : ");
    fflush(stdin);
    scanf("%d", &data[maxCount].semester);
    maxCount++;
  }
  else
  {
    printf("No more space.\n");
  }
}
int searchRec(stud *data, char key[])
{
  for(int i = 0 ; i < maxCount; i++){
    if(strcmp(key, data[i].roll_no) == 0)
    {
      printf("RECORD FOUND!!!!\n");
      printf("%s\t%s\t", data[i].roll_no,data[i].name);
      printf("%s\t%d\n", data[i].branch, data[i].semester);
      return i;
    }
  }
  return -1;
}
void traverseRecord(stud *data){
  FILE *fpointer = fopen("myRecord.txt", "w");
    printf("Name\tBranch\tRollNo.\tSemester\n");
  for(int i = 0; i < maxCount; i++)
  {
    fprintf(fpointer,"%s %s %s %d\n", data[i].name, data[i].branch, data[i].roll_no, data[i].semester);
    printf("%s\t%s\t%s\t%d\n", data[i].name, data[i].branch, data[i].roll_no, data[i].semester);
  }
  fclose(fpointer);
}
void deleteRecord(stud *data)
{
  char roll_no_del[20];
  printf("Enter the roll no : ");
  fflush(stdin);
  gets(roll_no_del);
  int result = searchRec(data, roll_no_del);
  if(result != -1)
  {
    for(int i = result ; i < maxCount; i++)
    {
      data[i] = data[i+1];
    }
    maxCount--;
    printf("RECORD DELETED!!!");
  }
  else
    printf("Not found\n");
}
void updateRecord(stud *data)
{
  char roll_no_del[20];
  printf("Enter the roll no : ");
  fflush(stdin);
  gets(roll_no_del);
  int result = searchRec(data, roll_no_del);
  if(result != -1)
  {
    printf("Enter updated Name :");
    fflush(stdin);
    gets(data[result].name);
    printf("Enter updated Branch : ");
    fflush(stdin);
    gets(data[result].branch);
    printf("Enter updated Roll no : ");
    fflush(stdin);
    gets(data[result].roll_no);
    printf("Enter updated Semester (1/2/3/4/5/6/7/8): ");
    fflush(stdin);
    scanf("%d",&data[result].semester);
    printf("RECORD UPDATED!!!");
  }
  else{
    printf("NO record found.\n");
  }
}
void reportgent(stud *data)
{
  int choice,key,count;
  char branch[32];
  printf("1. REPORT BASED ON SEMESTER\n2. REPORT BASED ON BRANCH\n");
  printf("Enter your choice: ");
  scanf("%d",&choice);
  switch(choice){
    case 1:
            printf("REPORT BASED ON Semester\n");
            printf("Enter semester: ");
            scanf("%d",&key);
            for(int i = 0;i < maxCount;i++){
              if(key==data[i].semester)
              {
                printf("%s\t%s\t", data[i].roll_no,data[i].name);
                printf("%s\t%d\n", data[i].branch, data[i].semester);
                count++;
              }
            }
           if (count!=0) {
             printf("Number of records in semester %d are %d\n",key,count);
           }
           else
            printf("NO records in semester %d\n",key);
          break;
    case 2:
            printf("REPORT BASED ON Branch\n");
            printf("Enter branch: ");
            fflush(stdin);
            gets(branch);
            for(int i = 0;i < maxCount;i++){
              if(strcmp(branch, data[i].branch) == 0)
              {
                printf("%s\t%s\t", data[i].roll_no,data[i].name);
                printf("%s\t%d\n", data[i].branch, data[i].semester);
                count++;
              }
            }
           if (count!=0) {
             printf("Number of records in branch %s are %d.\n",branch,count);
           }
           else
            printf("NO records in branch %d.\n",branch);
          break;
    default:
          printf("INVALID INPUT\n");
          break;
  }
}
void stdrec()
{

  printf("*********** STUDENT RECORD USING ARRAY ***********\n");
  printf("\nEnter Max Number of Students to work with:");
  scanf("%d",&num);
  stud *data = (stud *)malloc(sizeof(stud) * num);
  int choice,number;
  char d_roll[30],f;
  do{
    printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");

    printf("1. Input a record.\n");
    printf("2. Delete a record.\n");
    printf("3. Search a record.\n");
    printf("4. Traverse.\n");
    printf("5. Update a record.\n");
    printf("6. Generate the report\n");
    printf("7. EXIT\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        input(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 2:
        deleteRecord(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 3:
        printf("Enter the roll no : ");
        scanf("%s", &d_roll);
        int result = searchRec(data, d_roll);
        if(result == -1)
          printf("Not found\n");
        else
          printf("Found at postion %d", result + 1);
      printf("\nWant to return to main menu?(Y/N)");
  		scanf(" %c", &f);
        break;
      case 4:
        traverseRecord(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 5:
        updateRecord(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 6:
        reportgent(data);
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
      case 7:
        return;
        break;
      default:
        printf("Invalid Input\n");
        printf("\nWant to return to main menu?(Y/N)");
  			scanf(" %c", &f);
        break;
    }
  }while(f=='Y'||f=='y');

}
