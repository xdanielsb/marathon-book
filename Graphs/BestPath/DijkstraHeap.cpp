#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define forn(i,a) for (int i=0; i<a ; i++)
#define INF 2e7
struct edge{
	int to, weight;
	edge(){}
	edge(int _to, int _weight){
		to = _to;
		weight = _weight;
	}
	bool operator < (edge e) const {
		return weight > e.weight;
	}
};
typedef vector < edge > ve;
typedef vector < ve > vve;
typedef vector < int > vi;
typedef priority_queue< edge> pq;
inline void dijkstra(vve &adj, int src, int num_nodes){
  vi dist = vi(num_nodes+1,INF);
	pq  q;
  //by default
  q.push(edge(src,0));
  dist[src] = 0;
  //apply bfs
  while(!q.empty()){
    edge top = q.top();
    q.pop();
    int u = top.to;
    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i].to;
      if(dist[u] + adj[u][i].weight < dist[v]){
        dist[v] = dist[u] + adj[u][i].weight;
        q.push(edge(v,dist[v]));
      }
    }
  }
  //Show results of distances
  cout << "Distancias desde el origen ";
  cout << src << endl;
  forn(i, num_nodes){
    cout <<"Costo al nodo: " << i;
    cout << " ="<< dist[i] << endl;
  }
}

int main(){
	int nodes =5;
  vve adj(nodes);
	//from             to - weight
	adj[0].pb(edge(1, 6));
	adj[0].pb(edge(2, 2));
	adj[1].pb(edge(3, 5));
	adj[1].pb(edge(4, 7));
  int src = 1;
  dijkstra(adj, src, nodes);
  return 0;
}
