
#include<stdio.h>
int main()
{
    char A[]="decimal";
    char B[]="medical";
    int i,H[26];
    for(i=0;i<26;i++)H[i]=0;
    for(i=0;A[i]!='\0';i++)H[A[i]-97]++;
    for(i=0;B[i]!='\0';i++)
    {
        H[B[i]-97]--;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]!=0)
        {
            printf("NOT ANAGRAM");
            break;
        }
    }
    if(i==26)printf("Anagram");

return 0 ;
}