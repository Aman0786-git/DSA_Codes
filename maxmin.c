#include<stdio.h>
int max,min;
int arr[100];

void maxmin(int i,int j){
    int max1 , min1,mid;
    if(i==j)max=min=arr[i];
    else
    {
        if(i==j-1){
            if(arr[i]<arr[j]){
                max=arr[j];
                min=arr[i];
            }
            else
            {
                max=arr[i];
                min=arr[j];
            }
        }
        else{
            mid = (i+j)/2;
            maxmin(i,mid);
            max1=max;
            min1=min;
            maxmin(mid+1,j);
            if(max<max1)max=max1;
            if(min>min1)min=min1;
        }
    }
}
int main()
{
    int i,num;
    printf("Enter Size of Array: ");
    scanf("%d",&num);
    printf("Enter Array Elements: ");
    for(i=1;i<=num;i++){
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    min=arr[0];
    maxmin(1,num);
    printf("Maximum is: %d\n",max);
    printf("Minimum is: %d",min);
    return 0;
}