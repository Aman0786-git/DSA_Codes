#include<stdio.h>

int max(int i,int j)
{
    return i>j?i:j;
} 

int knapsack(int tw,int weight[],int value[],int n){

    if(n==0 || tw==0)return 0;

    if(weight[n-1]>tw){
       return knapsack(tw,weight,value,n-1);
    }
    else{
        return max(value[n-1]+ knapsack(tw-weight[n-1],weight,value,n-1),knapsack(tw,weight,value,n-1));        
    }
}

int main(){
    int wt[]={50,40,50};
    int val[]={20,40,30};
    int tw = 50;
    int  n=3;
    printf("%d",knapsack(tw,wt,val,n));
    return 0;
}