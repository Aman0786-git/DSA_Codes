#include<stdio.h>
// Using Recursion OF --> O(2^n)  
// More Time Consuming and More No. Of Calls 
/* int fibo(int n )
{
    if(n<=1)    
    return n;
    return fibo(n-1)+fibo(n-2);
}
 */

// Using Recursion OF ===> O(n) 
// Less Time Consuming and Lesser No. of Calls 
int F[9];
int fibo(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
        F[n-2]=fibo(n-2);
        if(F[n-1]==-1)
        F[n-1]=fibo(n-1);
        return F[n-2]+F[n-1];
    }
}
int main()
{   int i, n=11;
      for(i=0;i<n;i++)
      {
           F[i]=-1 ;
      }
    printf("%d term of fibonacci series is  : %d" ,n,fibo(n));
}