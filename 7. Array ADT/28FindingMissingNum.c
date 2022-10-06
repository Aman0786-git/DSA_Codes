#include<stdlib.h>
#include<stdio.h>
 
// Finding Single missing number in a array using formula -----> O(n^2)
/* int main()
{ int n,sumArr,sum=0;
  int arr[10] = {1,2,3,4,5,6,8,9,10,11};
   n = arr[9];
   sumArr = n*(n+1)/2 ;
   for(int i=0;i<10;i++)
   {
    sum+=arr[i];
   }
   printf("Missing number is : %d",sumArr-sum);
return 0 ;
} */

//  Finding Single missing number in a array using index difference
/* int main()
{ int n,diff;
  int arr[10] = {1,2,3,4,5,6,8,9,10,11};
  diff = arr[0]-0;

   for(int i=0;i<10;i++)
   {
        if(arr[i]-i!=diff)
        {
           printf("Missing number is : %d",i+diff);
           break;
        }
   }
return 0 ;
} */

//Finding  more than one missing element in an array using index differrence method ->> O(n^2)

/* int main()
{
    int n , diff;
    int arr[10] = {6,7,8,10,11,14,15,16,17,18};
    diff= arr[0]-0;
    for(int i=0;i<10;i++)
    {
        if(arr[i]-i != diff)
        {
            while (arr[i]-i>diff)
            {
                printf("Missing Num is : %d\n",i+diff);
                diff++;
            }
            
        }
    }
 
} */
//Finding  more than one missing element in an array using hash method ->> O(n)

int main()
{
    int low,high,i;
    int arr[] = {3,7,4,9,12,6,1,11,2,10};
    int n=sizeof(arr)/sizeof(int);
    high = 12 ; //Maximum Number in the array
    low = 1 ; // lowest number in the array
    int hash[high+1] ;
    for(i=0;i<high;i++)
        hash[i]=0;

    for(i=0;i<n;i++)
         hash[arr[i]]++;
    for(i=low;i<=high;i++)
    {
        if(hash[i]==0)
        printf("Missing Number is : %d\n",i);
    }
    return 0; 
}