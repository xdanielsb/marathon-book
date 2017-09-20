#include <iostream>
#include <queue>
using namespace std;
typedef priority_queue<edge> pq;
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
int main(){
  pq edges;
  edges.push(edge(1, 23));
  edges.push(edge(2, 3));
  edges.push(edge(3, 10));
  edges.push(edge(4, 11));
  edges.push(edge(5, 4));
  while(!edges.empty()){
    edge a = edges.top();
    edges.pop();
    cout << a.to << endl;
  }
}
