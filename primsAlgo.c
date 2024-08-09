#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define V 5

int minKey(int key[],bool mstSet[] ){
    int min=INT_MAX,minIndex;
    for(int v=0;v<V;v++)
    {
        if(mstSet[v]==false && key[v]<=min)
        {
            min=key[v];
            minIndex=v;
        }
    }
    return minIndex;
}

void printMST(int parent[],int graph[V][V]){
    printf("Edge\t\tWeight\n");
    for(int i=1;i<V;i++){
        printf("%d - %d \t\t %d\n",parent[i],i,graph[i][parent[i]]);
    }

}

void primMST(int graph[V][V]){
    int parent[V],key[V];
    bool MSTset[V];
    for(int i=0;i<V;i++){
        MSTset[i]=false;
        key[i]=INT_MAX;
    }
    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<V-1;count++)
    {
        int u = minKey(key,MSTset);
        MSTset[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v] && MSTset[v]==false && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }

    }
    printMST(parent,graph);
}

int main(){
    int graph[V][V]={
                        { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } 
    };
    primMST(graph);
    return 0;
}