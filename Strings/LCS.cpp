#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
	Longest common subsequence
*/
const int M_MAX = 20; // Máximo size del String 1
const int N_MAX = 20; // Máximo size del String 2
int m, n; // Size de Strings 1 y 2
string X; // String 1
string Y; // String 2
int memo[M_MAX + 1][N_MAX + 1];
int lcs (int m, int n) {
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) memo[i][j] = 0;
      else if (X[i - 1] == Y[j - 1]) memo[i][j] = memo[i - 1][j - 1] + 1;
      else memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
    }
  }
  return memo[m][n];
}
int main(){
  X = "XMJYAUZ";
  Y = "MZJAWXU";
  
  cout << lcs(X.size(), Y.size()) <<endl;
  //Sol = MJAU
  return 0;
}
