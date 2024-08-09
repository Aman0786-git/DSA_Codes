#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 5

int minDistance(int dist[],bool sptset[]){
    int min_index,min=INT_MAX;
    for(int i=0;i<V;i++){
        if(sptset[i]==false && dist[i]<=min)
        {
            min_index=i;
            min = dist[i];
        }
    }
    return min_index;
}

void printSol(int dist[])
{   printf("Vertex\t\tDistance from Source\n");
    for(int i=0;i<V;i++){
        printf("%d\t\t%d\n",i,dist[i]);
    }
}
void dijkstra(int graph[V][V],int src){
    int dist[V];
    bool sptset[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptset[i]=false;
    }
    dist[src]=0;
    
    for(int count =0;count<V-1;count++){
        int u= minDistance(dist,sptset);
        sptset[u]=true;

        for(int v=0;v<V;v++)
        {

        if(!sptset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
        {
            dist[v]=dist[u]+graph[u][v];
        }
        }
    }
    printSol(dist);
}

int main()
{
    int graph[V][V]={
        {0,1,0,2,0},
        {3,4,0,5,0},
        {0,4,1,3,0},
        {0,5,2,0,1},
        {0,4,0,3,2}, 
    };
    dijkstra(graph,0);
    return 0;
}