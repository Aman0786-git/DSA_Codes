#include<stdio.h>

// Changing Upper case to lower case
/* int main()
{
    char A[] = "WELCOME";

    for(int i=0;A[i]!='\0';i++)
    {
        A[i]+=32; //upppercase to lowercase
        // A[i]-=32 ; //Lowercase to uppercasex
    }
    printf("%s",A);

return 0 ;
} */

// Uppercase to lower and lower to uppercase
int main()
{
    char A[] = "wElComE";
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<=90)
        A[i]+=32;
        else if(A[i]>=97 && A[i]<=122)
        A[i]-=32;
    }
    printf("%s",A);
}