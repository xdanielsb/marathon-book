#include <bits/stdc++.h>
#define pb push_back
#define NUM_NODES 20
using namespace std;
vector < int > g[NUM_NODES];
int vis[NUM_NODES];
enum {WHITE, GRAY, BLACK};
void dfs(int o){
    vis [o] = GRAY; //semi-visited
    for (int i = 0; i < g[o].size(); i++){
        int v = g[o][i];
        if (vis[v] == GRAY)
              cout << "Cycle to " << o <<  endl;
        // visit neighbors
        else if (vis[v] == WHITE) dfs(v);
    }
    cout << o << endl;
    vis[o] = BLACK; //visited;
}
int main(){
    g[0].pb(1);  g[0].pb(2);
    g[0].pb(3);  g[1].pb(4);
    g[1].pb(5);  g[2].pb(6);
    g[3].pb(7);  g[4].pb(0);
    g[6].pb(0);
    dfs(0);
    return 0;
}
