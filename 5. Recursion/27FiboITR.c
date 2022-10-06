#include<stdio.h>
// Using Iteration of ===> O(n) ;
    int fibo(int n)
{
   int n1=0,n2=1,n3,i;
   for(i=2;i<n;i++)
   {  n3= n1+n2;
      n1=n2;
      n2=n3;
   }
   return n3;
}
int main()
{   int n=11; 
    printf("%d term of fibonacci series is  : %d" ,n,fibo(n));
}
