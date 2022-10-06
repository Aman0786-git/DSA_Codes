#include<stdio.h>
// O(n) --> More memory usage than others
int sumNat(int n){
   if(n==0)
   {  printf("Invalid Input\n");
      return 0 ;
   }
   else
   return n + sumNat(n-1) ;
}               
int main()
{
    int num ,sum;
    printf("Enter Term Number: ");
    scanf("%d",&num);
    sum = sumNat(num);
    printf("Sum of Natural Number Upto %d is : %d ",num,sum);
    return 0 ;
}
/*
//  Using Formula  --> O(1) - Less Space and Time than Others
  return n*(n+1)/2 ;

// Using Loop   -->  O(n) - Less Space than recursion
  for(i=1;i<=n;i++)
  {
     sum+=i ;
  }
*/