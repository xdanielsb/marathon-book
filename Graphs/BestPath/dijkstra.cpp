
#include <stdio.h>
#include <limits.h>
#define V 9

inline  int show_sol(int dist[], int n){
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++){
      printf("%d \t %d\n", i, dist[i]);
   }
}

int min_dis(int dist[], bool is_set[]){
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++){
        if (is_set[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        }
   }
   return min_index;
}

inline  void dijkstra(int graph[V][V], int src){
     int dist[V];
     bool is_set[V];
     for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, is_set[i] = false;
     }
     dist[src] = 0;
     for (int count = 0; count < V-1; count++){
       int u = min_dis(dist, is_set);
       is_set[u] = true;

       for (int v = 0; v < V; v++){
         if (!is_set[v] && graph[u][v] 
                 && dist[u] != INT_MAX
                 && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
       }
     }
     show_sol(dist, V);
}
int main(){
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    //distances from all points to 1
    dijkstra(graph, 1);
    return 0;
}
