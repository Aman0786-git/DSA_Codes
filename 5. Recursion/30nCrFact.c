#include<stdio.h>
// nCr using Factorial Method
int fact(int n)
{
   if(n==0)
   return 1;
   return fact(n-1)*n;
}

int C(int n,int r)
{
    int num,den;
    num = fact(n);
    den= fact(r)*fact(n-r);
    return num/den;
}

int main()
{
  int n=5,r=4;
  if(n>=r)
  {
  printf("%dC%d is : %d ",n,r,C(n,r));
  }
  else
  printf("Invalid Input");
  return 0 ;
}