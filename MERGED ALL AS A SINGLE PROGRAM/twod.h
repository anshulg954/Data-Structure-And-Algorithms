#include <stdio.h>
int r1,c1,temporary;
void matrixInput(int mat[r1][c1]);
void matrixPrint(int mat[r1][c1]);
void matrixAdd(int mat1[r1][c1], int mat2[r1][c1], int res[r1][c1]);
void matrixSub(int mat1[r1][c1], int mat2[r1][c1], int res[r1][c1]);
void matrixTrans1(int mat1[r1][c1],int res[r1][c1]);
void matrixTrans2(int mat2[r1][c1],int res[r1][c1]);
void twod()
{

  printf("\n******** 2D ARRAY OPERATIONS ********\n");
    printf("Enter no. of rows & columns in matrix\n");
    scanf("%d\n%d",&r1,&c1);
    char x;
    int mat1[r1][c1], mat2[r1][c1], res[r1][c1],choice;
    printf("Enter elements in first matrix of size %dx%d: \n", r1, c1);
    matrixInput(mat1);
    printf("\nEnter elements in second matrix of size %dx%d: \n", r1, c1);
    matrixInput(mat2);
    printf("\nMatrix1 before operations is:\n");
    matrixPrint(mat1);
    printf("\nMatrix2 before operations is:\n");
    matrixPrint(mat2);
    do{
    printf("\n--------    AVAILABLE OPERATIONS ARE    -----------\n");
    printf("1.ADD\n2.SUB\n3.Transpose matrix1\n4.Transpose matrix2\n5.EXIT\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
      matrixAdd(mat1, mat2, res);
      printf("\nSum of first and second matrix gives: \n");
      matrixPrint(res);
      printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &x);
      break;
      case 2:
      matrixSub(mat1, mat2, res);
      printf("\nSubtraction of first from second matrix gives: \n");
      matrixPrint(res);
      printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &x);
      break;
      case 3:
      matrixTrans1(mat1,res);
      printf("\nTranspose of Matrix1 is:\n");
      matrixPrint(res);
      printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &x);
      break;
      case 4:
      matrixTrans1(mat2,res);
      printf("\nTranspose of Matrix2 gives:\n");
      matrixPrint(res);
      printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &x);
      break;
      case 5:
       return;
       break;
      default:
      printf("Invalid Input\n");
      printf("Want to return to main menu?(Y/N)");
     scanf(" %c", &x);
     break;
    }
  }while (x=='y'||x=='Y');
}

void matrixInput(int mat[r1][c1])
{
    int i, j;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
}
void matrixPrint(int mat[r1][c1])
{
    int i, j;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

void matrixAdd(int mat1[r1][c1], int mat2[r1][c1], int res[r1][c1])
{
    int i, j;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            *(*(res + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }
}
void matrixSub(int mat1[r1][c1], int mat2[r1][c1], int res[r1][c1])
{
    int i, j;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            *(*(res + i) + j) =  *(*(mat2 + i) + j)-*(*(mat1 + i) + j);
        }
    }
}
void matrixTrans1(int mat1[r1][c1],int res[r1][c1])
{
    int i, j;
    for (i = 0; i < c1; i++)
    {
        for (j = 0; j < r1; j++)
        {
            *(*(res + i) + j) = *(*(mat1 + j) + i);
        }
    }
}
