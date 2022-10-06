#include<stdio.h>
int main()
{   
    int i;
   char *name = "Aman" ;
   for(i=0;name[i]!='\0';i++){}
   printf("%s\n",name);
   printf("Length : %d\n",i);
 
return 0 ;
}