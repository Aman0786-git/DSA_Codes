#include<stdlib.h>
#include<stdio.h>

//finding dublicates in a sorted array Method-1
/* int main()
{   
    int n,lastDupicate=0,i;
    int arr[] = {2,3,5,5,6,7,10,11,12,15,15,15,20};
    n = sizeof(arr)/sizeof(int);

    for(i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1] && arr[i]!=lastDupicate)
        {
            lastDupicate = arr[i];
            printf("%d\n",lastDupicate);
        }
    }
return 0 ;
} */

// Finding duplicates elements and how many times it is appearing in sorted array
/* int main()
{
   int i,n,j=0;
   int arr[] = {2,3,5,5,6,7,10,11,12,15,15,15,20};
    n = sizeof(arr)/sizeof(int);

    for(i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            j=i+1;
            while(arr[i]==arr[j])j++;
            printf("%d is appearing %d times\n",arr[i],j-i);
            i=j-1;
        }
    }
} */

// Finding duplicates elements and how many times it is appearing in sorted array using Hashing
int main()
{
    int i,n,high,low;
   int arr[] = {2,3,5,5,6,7,10,11,12,15,15,15,20};
    n = sizeof(arr)/sizeof(int);
    high = 20 ;//maximum number in array
    low = 2 ;//Minimum number in array
    int hash[high+1];
    
    for(i=0;i<high+1;i++)hash[i]=0;
    for(i=0;i<n;i++)hash[arr[i]]++;
    for(i=0;i<high+1;i++)
    {
        if(hash[i]>1)
        printf("%d appeared %d times\n",i,hash[i]);
    }

}