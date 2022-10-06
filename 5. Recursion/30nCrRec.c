#include<stdio.h>
// nCr using Recursion Method;
int C(int n,int r)
{ 
    if(n==r || r==0)
    return 1;
    return C(n-1,r-1)+C(n-1,r);

}

int main()
{
  int n=4,r=2;
  printf("%dC%d is : %d ",n,r,C(n,r));
  
  return 0 ;
}