#include <cstdio>
#include <vector>
#define f first
#define s second
#define pb push_back
#define MAX 2e9
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

void init(vi &distances, int src) {
  for(int i=0; i<distances.size(); i++)
    distances[i] = MAX;
  distances[src] = 0;
}
/*
 *Given a graph and a source vertex src in graph,
 *find shortest paths from src to all vertices in
 *the given graph. The    graph may contain negative weight edges.
*/
void bellmanFord(vvpii &graph, vi &dist) {
  for(int i=0; i<graph.size() - 1; i++) {
    for(int u = 0; u < graph.size(); u++) {
      for(pii v : graph[u]) {
        dist[v.f] = min(dist[v.f], v.s + dist[u]);
      }
    }
  }
}

int main() {
    vvpii adj(5);
    vi d(5);
    int src = 0;
    init(d, src);
    adj[0].pb({1, 6}); adj[0].pb({3, 7});
    adj[1].pb({2, 5}); adj[1].pb({3, 8});
    adj[1].pb({4, -4}); adj[2].pb({1, -2});
    adj[3].pb({2, -3}); adj[3].pb({4, 9});
    adj[4].pb({0, 2}); adj[4].pb({2, 7});
    bellmanFord(adj, d);
    printf("from node= %d\n", src);
    for(int i=0; i<d.size(); i++) {
        printf("to %d = %d \n",i, d[i]);
    }
    printf("\n");
    return 0;
}
