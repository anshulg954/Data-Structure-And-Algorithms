#include <stdio.h>
void main()
{
  int choice;
  char x;
  do{
    system("cls");
    printf("******** MATRIX MULTIPLICATION *********\n");
    printf("\n--------    AVAILABLE OPTIONS ARE    -----------\n");
    printf("1.Go to MATRIX MULTIPLICATION directly.\n2.EXIT");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
  switch (choice) {
    case 1:
        matmul();
        printf("Want to return to main menu?(Y/N)");
        scanf(" %c", &x);
        break;
    case 2:
        return;
    default:
        printf("Invalid Input\n");
        printf("Want to return to main menu?(Y/N)");
       scanf(" %c", &x);
  }
  }while (x=='y'||x=='Y');
}
 void matmul(){
  printf("\n******** MATRIX MULTIPLICATION MENU ********\n");
  int row_matrix1, column_matrix1, row_matrix2, column_matrix2, i, j, k, sum = 0;
  int matrix1[10][10], matrix2[10][10], multiply[10][10];
  printf("Enter number of rows and columns of matrix 1\n");
  scanf("%d%d", &row_matrix1, &column_matrix1);
  printf("Enter elements of first matrix\n");
  for (i = 0; i < row_matrix1; i++)
    for (j = 0; j < column_matrix1; j++)
      scanf("%d", &matrix1[i][j]);
  printf("Enter number of rows and columns of matrix 2\n");
  scanf("%d%d", &row_matrix2, &column_matrix2);
  if (column_matrix1 != row_matrix2)
    printf("MATRIX MULTIPLICATION NOT POSSIBLE\n");
  else
  {
    printf("Enter elements of second matrix\n");
    for (i = 0; i < row_matrix2; i++)
      for (j = 0; j < column_matrix2; j++)
        scanf("%d", &matrix2[i][j]);
    for (i = 0; i < row_matrix1; i++) {
      for (j = 0; j < column_matrix2; j++) {
        for (k = 0; k < row_matrix2; k++) {
          sum = sum + matrix1[i][k]*matrix2[k][j];
        }
        multiply[i][j] = sum;
        sum = 0;
      }
    }
    printf("Product of the matrices:\n");
    for (i = 0; i < row_matrix1; i++) {
      for (j = 0; j < column_matrix2; j++)
        printf("%d\t", multiply[i][j]);
      printf("\n");
    }
  }
}
