// Finding Minimum and maximum number in a single sacn
#include<stdlib.h>
#include<stdio.h>
int main()
{   int i;
    int arr[] = {8,3,4,2,5,10,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int min = arr[0];
    int max= arr[0];

    for(i=0;i<n;i++)
    {
        if(arr[i]<min)
        min = arr[i];
        else if(arr[i]>max)
        max = arr[i];
    }
    printf("Minimum No. is : %d\n",min);
    printf("Maximum No. is : %d",max);
return 0 ;
}