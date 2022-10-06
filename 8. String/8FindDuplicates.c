#include<stdlib.h>
#include<stdio.h>

// finding Duplicates in a string using hash table
/* int main()
{   
        char A[] = "finding";
        int i;
        int H[26]={0};
        for(i=0;A[i]!='\0';i++)
        {
            H[A[i]-97]++;
        }
        for(i=0;i<26;i++)
        {
            if(H[i]>1)
            printf("%c Appears %d times\n",i+97,H[i]);
        }
        return 0 ;
} */

//Finding Duplicate in a String using BItwise Operator

int main()
{
    char A[]="fuding";
    int x=0,H=0,i;
    for(i=0;A[i]!='\0';i++)
    {
        x=1;
        x=x<<A[i]-97;
        if(x&H)
        printf("%c is Duplicate \n",A[i]);
        else
        {
        H=x|H;
        }
    }
    
    return 0;

}