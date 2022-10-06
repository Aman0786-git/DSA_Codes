#include<stdio.h>

/* int power(int num,int pow)
{
    if(pow==0)
    return 1 ;
    else
    return num * power(num,pow-1);

}
 */

int power(int num,int pow)
{
    if(pow==0)
    return 1;
    if(pow%2==0)
    return power(num*num,pow/2);
    else
    return num*power(num*num,(pow-1)/2);
}
int main()
{
    int num=2,pow=3 ,res ;
    res = power(num,pow);
    printf(" %d ^ %d is  : %d ",num,pow,res);
    return 0 ;
}