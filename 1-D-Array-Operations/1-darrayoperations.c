#include<stdio.h>
#include<stdlib.h>
int a[20],b[20],c[40];
int m,n,p,val,i,j,key,key1,pos;
//Function Prototype
void create();
void display();
void insert();
void del();
void search();
void update();
void main()
{
        int choice;
        do{
                printf("\n************ 1-D ARRAY **********\n");
                printf("\n--------    AVAILABLE OPERATIONS ARE   -----------\n");
                printf("1.Create an Array.\n");
                printf("2.Traverse.\n");
                printf("3.Insert data.\n");
                printf("4.Delete data.\n");
                printf("5.Search data.\n");
                printf("6.Update data.\n");
                printf("7.EXIT\n");
                printf("-----------------------");
                printf("\nEnter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        insert();
                                        break;

                        case 4:
                                        del();
                                        break;
                        case 5:
                                        search();
                                        break;
                        case 6:
                                        update();
                                        break;
                        case 7:
                                        return;
                                        break;
                        default:
                                        printf("\nInvalid choice:\n");
                                        break;
                }
        }while(choice!=7);
}
void create() //creating an array
{
        printf("\nEnter the size of the array elements:\t");
        scanf("%d",&n);
        printf("\nEnter the elements for the array:\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
}
void display()  //displaying an array elements
{
        int i;
        printf("\nThe array elements are:\n");
        for(i=0;i<n;i++){
                 printf("%d\t",a[i]);
         }
 }
void insert()   //inserting an element in to an array
{
    printf("\nEnter the position for the new element:\t");
    scanf("%d",&pos);
    printf("\nEnter the element to be inserted :\t");
    scanf("%d",&val);
    for(i=n;i>=pos-1;i--)
        {
                a[i+1]=a[i];
        }
        a[pos-1]=val;
        n=n+1;
}
void del()      //deleting an array element
{
        printf("\nEnter the position of the element to be deleted:\t");
        scanf("%d",&pos);
        val=a[pos-1];
        for(i=pos-1;i<n;i++)
        {
            a[i]=a[i+1];
        }
        printf("\nThe deleted element is =%d",val);
        n=n-1;
}
void search()   //searching an array element
{
        printf("\nEnter the element to be searched:\t");
        scanf("%d",&key);
        for(i=0;i<n;i++)
        {
                if(a[i]==key)
                {
                        printf("\nThe element is present at position %d",i+1);
                        break;
                }
        }
        if(i==n)
        {
                printf("\nThe entered element is not present");
        }
}

void update()
{
        printf("\nEnter the element to update:\t");
        scanf("%d",&key);
        printf("\nEnter the value of element to update:\t");
        scanf("%d",&key1);
        for(i=0;i<n;i++)
        {
                if(a[i]==key)
                {
                    a[i]=key1;
                    break;
                }
        }
}
