#include <bits/stdc++.h>
#define numVertices 9
inline  int showSol(int dist[], int n){
  printf("numVerticesertex\tDistance from Source\n");
  for (int i = 0; i < numVertices; i++)
    printf("%d\t%d\n", i, dist[i]);
}
int minDis(int dist[], bool is_set[]){
  int min = INT_MAX, min_index;
  for (int v = 0; v < numVertices; v++){
    if (is_set[v] == false && dist[v] <= min){
      min = dist[v], min_index = v;
    }
  }
  return min_index;
}

inline  void dijkstra(int graph[numVertices][numVertices], int src){
     int dist[numVertices];
     bool is_set[numVertices];
     for (int i = 0; i < numVertices; i++){
        dist[i] = INT_MAX, is_set[i] = false;
     }
     dist[src] = 0;
     for (int count = 0; count < numVertices-1; count++){
       int u = minDis(dist, is_set);
       is_set[u] = true;
       for (int v = 0; v < numVertices; v++){
         if (!is_set[v] && graph[u][v]
                 && dist[u] != INT_MAX
                 && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
       }
     }
     showSol(dist, numVertices);
}
int main(){
   int graph[numVertices][numVertices] =
      {{0, 4, 0, 0, 0, 0, 0, 8, 0},
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
