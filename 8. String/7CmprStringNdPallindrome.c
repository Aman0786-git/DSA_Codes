#include<stdlib.h>
#include<stdio.h>


int main()
{
        char A[] = "painter";
        char B[] = "painting";
        int i,j;
        for(i=0,j=0;A[i]!='\0' && B[i]!='\0';i++,j++)
        {
            if(A[i]!=B[j])break;
        }
        if(A[i]==B[j])printf("EQUAL");
        else if(A[i]<B[j])printf("First String is SMALLER");
        else
        printf("First String is GREATER");


return 0 ;
}