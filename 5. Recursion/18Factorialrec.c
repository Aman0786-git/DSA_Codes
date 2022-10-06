#include<stdio.h>

int fact(int n)
{
    if(n==0 || n==1)
    return 1;
    else
    return n * fact(n-1);
}
int main()
{
   int num ,factorial ;

   printf("Enter Nummber : ");
   scanf("%d",&num);
   if(num>0)
   {
   factorial = fact(num);
   printf("Factorial Of %d is : %d ",num,factorial);
   }
   else
   printf("Invalid Number");
   return 0 ;
}