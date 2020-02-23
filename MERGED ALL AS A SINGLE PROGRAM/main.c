#include <stdio.h>
#include "oned.h"
#include "twod.h"
#include "matrixmul.h"
#include "stdrec.h"
#include "stdrecll.h"
#include "stdrecdll.h"
#include "starr.h"
#include "stll.h"
#include "stdll.h"
void main(){
  int choice;
  char f;
do{
  system("cls");
  printf("********WELCOME TO MY LAB IMPLEMENTATION ********\n");
  printf("Submitted To: Dr. R.B. Patel\nSubmitted By: Anshul Gupta\n\t\tCO18311\n");
  printf("\n--------    List of Implemented Programs (15.07.2019-14.10.2019)  -----------\n");
  printf("1.1D ARRAY OPERATIONS\t----\t(Create/Insert/Search/Traverse/Update/Delete).\n");
  printf("2.MATRIX MULTIPLICATION.\n");
  printf("3.STUDENT RECORD USING ARRAY\t----\t(Input/Search/Traverse/Update/Delete).\n");
  printf("4.STUDENT RECORD USING SINGLE-LINKED-LIST\t----\t(Create/Insert/Search/Traverse/Update/Delete).\n");
  printf("5.STUDENT RECORD USING DOUBLE-LINKED-LIST\t----\t(Create/Insert/Search/Traverse/Update/Delete).\n");
  printf("6.2D ARRAY OPERATIONS\t----\t(Add/Subtract/Transpose).\n");
  printf("7.STACK USING ARRAY\t----\t(Push/Pop/Peep/Traverse/Update).\n");
  printf("8.STACK USING SINGLE-LINKED-LIST\t----\t(Push/Pop/Peep/Traverse/Update).\n");
  printf("9.STACK USING DOUBLE-LINKED-LIST\t----\t(Push/Pop/Peep/Traverse/Update).\n");
  printf("\nEnter your choice:\n");
  scanf("%d",&choice);
 switch(choice){
  case 1:
  printf("\n******** DATA STRUCTURE ARRAY ********\n");
  printf("\nSome important points about 1-D Array:\n");
  printf("\nAn array is a linear data structure.\nIt is a collection of similar data elements i.e. contain homogenous data.\nThe elements of the array are stored in consecutive memory locations and are referenced by an index.\nThe index is an ordinal number which is used to identify an element of the array.\n");
  printf("\nFollowing operations can be performed on an 1-D array:\n");
  printf("1.Create an Array.\n");
  printf("2.Traverse.\n");
  printf("3.Insert data.\n");
  printf("4.Delete data.\n");
  printf("5.Search data.\n");
  printf("6.Update data.\n");
      oned();
      printf("\nWant to return to Starting menu?(Y/N)");
      scanf(" %c", &f);
      break;
  case 2:
      matrimul();
      printf("\nWant to return to Starting menu?(Y/N)");
      scanf(" %c", &f);
      break;
  case 3:
      stdrec();
      printf("\nWant to return to Starting menu?(Y/N)");
      scanf(" %c", &f);
      break;
  case 4:
       stdrecll();
       printf("\nWant to return to Starting menu?(Y/N)");
       scanf(" %c", &f);
       break;
  case 5:
      stdrecdll();
      printf("\nWant to return to Starting menu?(Y/N)");
      scanf(" %c", &f);
      break;
  case 6:
      twod();
      printf("\nWant to return to Starting menu?(Y/N)");
      scanf(" %c", &f);
      break;
  case 7:
          starr();
      printf("\nWant to return to Starting menu?(Y/N)");
      scanf(" %c", &f);
      break;
  case 8:
      stll();
      printf("\nWant to return to Starting menu?(Y/N)");
      scanf(" %c", &f);
      break;
  case 9:
        stdll();
        printf("\nWant to return to Starting menu?(Y/N)");
        scanf(" %c", &f);
        break;
  default:
      printf("\nEnter a valid choice");
      printf("\nWant to return to Starting menu?(Y/N)");
      scanf(" %c", &f);
      break;
  }
}while(f=='y'||f=='Y');
}
