#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector < int > vi;
vi dis;
vector < vi > graph;
void show_distances(){
  for( int i = 0; i< dis.size(); i++){
    cout << i << " : " << dis[i] << "\n";
  }
}
void bfs(int origin){
  queue < int > q;
  dis[origin] = 0;
  q.push(origin);
  while( q.size() > 0){
    int front = q.front(); q.pop();
    for(int son: graph[front]){
      if(dis[son] == -1){
        dis[son] = dis[front] +1;
        q.push(son);
      }
    }
  }
}

int main(){
  int num_nodes = 5;
  dis.assign(num_nodes, -1);
  graph.resize(num_nodes);
  graph[0].pb(1);
  graph[0].pb(2);
  graph[0].pb(3);
  graph[1].pb(4);
  bfs(0);
  show_distances();
  return 0;
}
