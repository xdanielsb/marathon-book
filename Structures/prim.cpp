#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10005;
typedef pair <int, int> edge;
// Pareja (nodo, peso)
typedef pair <int, int> weight_node; // Pareja (peso, nodo)
vector <edge> g[MAXN];
// Lista de adyacencia
bool visited[MAXN];


// Retorna el costo total del MST
int prim(int n){ // n = número de nodos
    for (int i = 0; i <= n; ++i) visited[i] = false;
    int total = 0;

    priority_queue<weight_node, vector <weight_node>,
    greater<weight_node> > q;
    // Empezar el MST desde 0 (cambiar si el nodo 0 no existe)
    q.push(weight_node(0, 0));
    while (!q.empty()){
        int u = q.top().second;
        int w = q.top().first;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;
        total += w;
        for (int i = 0; i < g[u].size(); ++i){
            int v = g[u][i].first;
            int next_w = g[u][i].second;
            if (!visited[v]){
                q.push(weight_node(next_w, v));
            }
        }
    }
    return total;
}

int main(){
    //Nodo 0 se une al 1 con peso 1
    g[0].push_back(edge(1,1));
    //Nodo 0 se une al 2 con peso 2
    g[0].push_back(edge(2,2));
    //Nodo 0 se une al 3  con peso 3
    g[0].push_back(edge(3,3));
    
    g[1].push_back(edge(5,4));
    g[2].push_back(edge(4,5));
    g[3].push_back(edge(4,1));

    cout << prim(4);

    return 0;
}
