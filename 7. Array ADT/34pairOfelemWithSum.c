//finding pair of elements with sum a+b = k 

#include<stdlib.h>
#include<stdio.h>

//Method -1 O(n^2)
/* int main()
{   int n,i,j,k=10;
    int arr[]= {0,3,6,4,8,7,1,2,9,10};
    n = sizeof(arr)/sizeof(int);

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==k)
            printf("%d + %d = %d \n",arr[i],arr[j],k);
        }
    }
return 0 ;
} */



//Method -2  O(n) - Hash Method
/* int main()
{
    int n,i,high,low,k=10;
    int arr[]= {16,3,6,4,8,7,1,13,9,10};
    n = sizeof(arr)/sizeof(int);
    high = 16;

    int hash[high+1];
    for(i=0;i<high+1;i++)hash[i]=0;
    for(i=0;i<n;i++)
    {
        if(hash[k-arr[i]]>0 && k-arr[i]>=0)
        {
        printf("%d + %d = %d\n",arr[i],k-arr[i],k);
        }
        hash[arr[i]]++;
    }
   
} */


// Using while loop

int main()
{
        int n,sum=10;
    int arr[]= {1,3,4,5,8,7,9,10,11,12};
    n = sizeof(arr)/sizeof(int);
    int low = 0;
  int high = n - 1;
 
  while (low < high)
  {
    if (arr[low] + arr[high] == sum)
    {
      printf("%d + %d = %d\n",arr[low],arr[high],sum);
    }
    if (arr[low] + arr[high] > sum)
    {
      high--;
    }
    else
    {
      low++;
    }
  }
    return 0;
}