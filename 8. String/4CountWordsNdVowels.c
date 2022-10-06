#include<stdlib.h>
#include<stdio.h>
int main()
{   int word=1,vow=0;
    char A[] = "Hello I am Aman";
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]==' ')
        word++;
        else if(A[i]=='a' || A[i]=='e' ||A[i]=='i' ||A[i]=='o' ||A[i]=='u' ||A[i]=='A' ||A[i]=='E' ||A[i]=='I' ||A[i]=='O' || A[i]=='U')
        vow++;
    }
    printf("Number of Words: %d\n",word);
    printf("Number of vowels: %d",vow);
    return 0;
}