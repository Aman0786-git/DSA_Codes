#include<stdlib.h>
#include<stdio.h>

// Reversing Array using 2nd array
/* int main()
{
    char name[] = "Amanullah";
    char revName[10];
    int i,j ;
    for(i=0;name[i]!='\0';i++){
    }
    i=i-1;
    for( j=0;i>=0;i--,j++)
    {
        revName[j]=name[i];
    }
    revName[j]='\0';
    printf("Reversed Name is : %s ",revName );
return 0 ;
} */

// Reversing array without using 2nd array

    int main()
{
    char name[] = "Amanullah";
    int i,j ;
    for(i=0;name[i]!='\0';i++){
    }
    i=i-1;
    for(j=0;j<i;j++,i--)
    {   char temp;
            temp = name[j];
            name[j]=name[i];
            name[i]=temp;
    }
   
    printf("Reversed Name is : %s ",name );
return 0 ;
}