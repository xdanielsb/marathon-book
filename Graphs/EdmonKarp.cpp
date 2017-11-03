#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int max_flow(int n, int s, int t, int **arr)  {
  int *back = new int[n], cur, flow = 0;
  while(true) {
    for(int i=0; i<n; i++) back[i] = -1;
    queue<int> Q;
    Q.push(back[s] = s);
    while(!Q.empty()) {
      cur = Q.front(); Q.pop();
      if(cur == t) break;
      for(int i=0; i<n; i++) {
        if(arr[cur][i] > 0 && back[i] < 0) {
          back[i] = cur;
          Q.push(i);
        }
      }
    }
    if(back[t] < 0) break;
    int cap = INF; cur = t;
    while(cur != s) {
      cap = min(cap, arr[back[cur]][cur]);
      cur = back[cur];
    }
    assert(cap > 0 && cap < INF);
    cur = t;
    while(cur != s) {
      arr[back[cur]][cur] -= cap;
      arr[cur][back[cur]] += cap;
      cur = back[cur];
    }
    flow += cap;
  }
  delete[] back;
  return flow;
}

int main() {
    int n = 3;
    int **G = new int*[n];
    for(int i=0; i<n; i++) G[i] = new int[n];

    G[0][0] = 0; G[0][1] = 1000; G[0][2] = 0;
    G[1][0] = 0; G[1][1] = 0; G[1][2] = 1000;
    G[2][0] = 0; G[2][1] = 0; G[2][2] = 0;

    cout << max_flow(3, 0, 2, G) << endl;
    return 0;
}
