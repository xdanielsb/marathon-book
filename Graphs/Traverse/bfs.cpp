#include <bits/stdc++.h>
#define NUM_NODES 8
using namespace std;

vector < int > g[NUM_NODES];
int d[NUM_NODES];

void show(){
    for (int i = 0; i < NUM_NODES; i++){
        cout << i << " " << d[i] << endl;
    }
}
/*
 * s -> origin
 * n -> number of nodes
 */
void bfs(int o, int n){
    for (int i = 0; i<=n;  i++) d[i] = -1;
    queue < int > q;
    q.push(o);
    d[o]  = 0; 
    while(q.size() > 0){
        int  cur  = q.front(); q.pop();
        for ( int i = 0; i < g[cur].size(); i++){
            int next = g[cur][i];
            if(d[next] == -1){
                d[next] = d[cur] +1;
                q.push(next);
            }
        }
    }
}

int main(){

    g[0].push_back(1);
    g[0].push_back(2);
    g[0].push_back(3);
    g[1].push_back(4);
    g[1].push_back(5);
    g[2].push_back(6);
    g[3].push_back(7);
    
    bfs(0, NUM_NODES);

    show();


    return 0 ;
}
