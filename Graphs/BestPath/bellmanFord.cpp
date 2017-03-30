#include <cstdio>
#include <vector>
using namespace std;

#define MAX 2e9

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

void init(vi &distances, int s) {
    for(int i=0; i<distances.size(); i++)
        distances[i] = MAX;

    distances[s] = 0;
}

void bellman_ford(vvpii &graph, vi &dist) {
    for(int i=0; i<graph.size() - 1; i++) {
        for(int u = 0; u < graph.size(); u++) {
            for(pii v : graph[u]) {
                dist[v.first] = min(dist[v.first], v.second + dist[u]);
            }
        }
    }
}

int main() {

    vvpii adjList(5);
    vi d(5);

    init(d, 0);

    adjList[0].push_back({1, 6});
    adjList[0].push_back({3, 7});

    adjList[1].push_back({2, 5});
    adjList[1].push_back({3, 8});
    adjList[1].push_back({4, -4});

    adjList[2].push_back({1, -2});

    adjList[3].push_back({2, -3});
    adjList[3].push_back({4, 9});

    adjList[4].push_back({0, 2});
    adjList[4].push_back({2, 7});

    bellman_ford(adjList, d);

    for(int i=0; i<d.size(); i++) {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}
