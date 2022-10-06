#include<stdlib.h>
#include<stdio.h>
// finding duplicates in a unsorted array Method - 1 : O(n^2)
/* int main()
{   int n,i,j,count;
    int arr[]= {8,3,6,4,6,5,6,8,2,6};
    n = sizeof(arr)/sizeof(int);
     
     for(i=0;i<n-1;i++)
     {
        count = 1;
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {

            count++;
            arr[j]=-1;
            }
        }
        if(arr[i]!=-1 && count>1)
        printf("%d appeared %d times \n",arr[i],count);
     }
    

    return 0 ;
} */


// finding duplicates in a unsorted array Method - 2 : O(n) Hash method

int main()
{   int n,i,high,low;
    int arr[]= {8,3,6,4,6,5,6,8,2,6};
    n = sizeof(arr)/sizeof(int);
    high = 8;
    low = 2 ;
    int hash[high+1];

    for(i=0;i<high+1;i++)hash[i]=0;
    for(i=0;i<n;i++)hash[arr[i]]++;
    for(i=0;i<high+1;i++)
    {
        if(hash[i]>1)
        printf("%d appeared %d times\n",i,hash[i]);
    }
}