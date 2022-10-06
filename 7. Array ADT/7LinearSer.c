#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    printf("\nElements are :\n");
    for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
}
void swap(int *x,int *y)
{
    int temp ;
    temp=*x;
    *x=*y;
    *y=temp;
}
int LinearSearch(struct Array *arr,int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {  //swap(&arr->A[i],&arr->A[i-1]);    //Transposition
             swap(&arr->A[i],&arr->A[0]);    //Move to front/Head
            return i ;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};
    printf("%d\n",LinearSearch(&arr,5));
    display(arr);
    return 0;
}