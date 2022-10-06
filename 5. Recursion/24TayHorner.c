#include<stdio.h>

/* double e(int x,int n) 
{     
    int s=1;
    for(;n>0;n--)
    {
        s=1+(x/n)*s;

    }
    return s ;

} */

double e(int x ,int n)
{
    static double s;
    if(n==0)
    return s;
    s = 1+x*s/n   ;
    return e(x,n-1);
    
}
int main()
{
   printf("%lf",e(1,10));   
   return 0 ;
   }