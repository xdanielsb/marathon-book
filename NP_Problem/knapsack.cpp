#include <bits/stdc++.h>
#include <algorithm>

// Maximo número de objetos
const int MAXN = 2005;
// Maximo tamano
const int MAXW = 2005;
// w[i] = peso del objeto i (i comienza en 1)
int w[MAXN];
int v[MAXN];
// dp[i][j] máxima ganancia si se toman un subconjunto de los
// objetos 1 .. i y se tiene una capacidad de j
int dp[MAXN][MAXW];


using namespace std;

int knapsack(int n, int W){
    for (int j = 0; j <= W; ++j) dp[0][j] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= W; ++j){
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    return dp[n][W];
}

int main(){
    int n = 10;
    int cont = n;
    for( int i = 0; i < n; i++){
        w[i] = i;
        v[i] = n--;
    } 
    
    cout << knapsack(10, 100);
}
