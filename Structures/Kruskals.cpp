#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<long long, pii> edge;
typedef vector<pii> vpii;
typedef vector<edge> E;

long long weight;
int vertex;

vpii mst(int n, E &edges, vb &vis) {
  weight = 0; vertex = 0;
  union_find uf(n);
  sort(edges.begin(), edges.end());
  vpii res;
  for(int i=0; i<edges.size(); i++) {
    int x = edges[i].second.first;
    int y = edges[i].second.second;
    if(uf.find(x) != uf.find(y)) {
      if(!vis[x]) {
        vertex++;
        vis[x] = true;
      }
      if(!vis[y]) {
        vertex++;
        vis[y] = true;
      }
      weight += edges[i].first;
      res.push_back(pii(min(x, y), max(x, y)));
      uf.unite(x, y);
    }
  }
  return res;
}

int main() {
  int v, e, x, y, w;
  while(scanf("%d %d", &v, &e) && (v + e)){
    E list(e);
    vb vis(v);
    for(int i=0; i<e; i++) {
      scanf("%d %d %d", &x, &y, &w);
      list[i] = edge(w, pii(x, y));
    }
    vpii answ = mst(v, list, vis);
    if(vertex == v) {
      printf("%lld\n", weight);
      sort(answ.begin(), answ.end());
      for(int i=0; i<answ.size(); i++){
        printf("%d %d\n", answ[i].first, answ[i].second);
      }
    }
    else printf("Impossible\n");
  }
  return 0;
}
