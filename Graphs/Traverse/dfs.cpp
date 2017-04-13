#include <bits/stdc++.h>
#define NUM_NODES 8

using namespace std;

vector < int > g[NUM_NODES];
int vis[NUM_NODES];
enum {WHITE, GRAY, BLACK};

/*
 * o -> origin
 */
void dfs(int o){
    vis [o] = GRAY; //semi-visited
    for (int i = 0; i < g[o].size(); i++){
        int v = g[o][i];
        if (vis[v] == WHITE) dfs(v); // visit neighbors
    }
    cout << o << endl;
    vis[o] = BLACK; //visited;
}


int main(){

    g[0].push_back(1);
    g[0].push_back(2);
    g[0].push_back(3);
    g[1].push_back(4);
    g[1].push_back(5);
    g[2].push_back(6);
    g[3].push_back(7);
    
    dfs(0);


    return 0;
}
