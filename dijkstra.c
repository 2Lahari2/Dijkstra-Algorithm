#include<stdio.h>
#define max 15
#define INF 9999

//function to find the shortest distance
void dijkstra(int adj[max][max], int n, int startnode){
    /* wei[max][max] - is the weight matrix of vertices with respect to each other.If not connected, then initialized to infinity
       dist[max][max] - is the distance matrix with distances of vertices with respect to starting node
       visited[max] - the vertices visited while determinig the shortest path
       pred[max] - previously visited vertice with respect to index*/
    int wei[max][max], dist[max], visited[max],min,next,pred[max],i,j;    
    
    // finding wei[max][max] from the adj[max][max]
    for(i=0;i<n;i++){                                                       
            for(j=0;j<n;j++){
                if(adj[i][j]==0){
                    wei[i][j] = INF;
                }
                else{
                    wei[i][j] = adj[i][j];
                }
            }
    }
    
    // initializing dist[max], visited[max], pred[i]
    for(i=0;i<n;i++){
        dist[i] = wei[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    dist[startnode] = 0;
    visited[startnode] = 1;
    int count = 1;
    // finding shortest path by going from vertice to vertice
    while(count<n-1){
        min = INF;
        for(i=0;i<n;i++){
            if((dist[i]<min) && (!visited[i])){
                min = dist[i];
                next = i;
            }
        }
            visited[next] = 1;
        for(i=0;i<n;i++){
                if(!visited[i]){
                    if((min+wei[next][i])<dist[i]){
                        dist[i] = min+wei[next][i];
                        pred[i] = next;
                    }
                }
        }
        count++;
    }
    
    // printing the shortest path from start node to all other nodes
    for(i=0;i<n;i++){
        if(i!=startnode){
            printf("\nDistance of node %d = %d\n",i,dist[i]);
            printf("\nPath = %d",i);
            j=i;
            do{
                j = pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
        }
    }
}




int main(){
    //adj[max][max] - adjacency matrix
    int n,i,j,adj[max][max],p;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix of the graph\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the starting node:");
    scanf("%d",&p);
    dijkstra(adj,n,p);
    return 0;
}


