#include <bits/stdc++.h>
using namespace std;

typedef vector < int > vi;
typedef vector < vi  > vii;
// w[i] = peso del objeto i (i comienza en 1)
vi w;
vi v;
// dp[i][j] máxima ganancia si se toman un subconjunto de los
// objetos 1 .. i y se tiene una capacidad de j
int ** dp;

int knapsack(int n, int W){
  for (int j = 0; j <= W; ++j) dp[0][j] = 0;
  for (int i = 1; i <= n; ++i){
    for (int j = 0; j <= W; ++j){
      dp[i][j] = dp[i-1][j];
      if (j - w[i] >= 0){
        dp[i][j] = max(dp[i][j],
          dp[i-1][j-w[i]] + v[i]);
      }
    }
  }
  return dp[n][W];
}

int main(){
  int numObjects = 10;
  int maxCapacity = 100;
  dp = new int*[numObjects];
  for (int i =0; i < maxCapacity; i++)
    dp[i]= new int[maxCapacity];

  w.resize(numObjects);
  v.resize(numObjects);
  int cont = numObjects;
  for( int i = 1; i < numObjects; i++){
    w[i] = i;
    v[i] = cont--;
  }
  cout << knapsack(10, 100);
}
