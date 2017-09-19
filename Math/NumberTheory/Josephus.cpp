#include <bits/stdc++.h>
#define show(x) cout << #x << " = "<< x << endl;
using namespace std;
//https://www.youtube.com/watch?v=uCsD3ZGzMgE
int jose(int n, int k) {
  if (n == 1) return 0;
  if (n < k) return (jose(n-1,k)+k)%n;
  int np = n - n/k;
  return k*((jose(np,k)+np-n%k%np)%np) / (k-1);
}

int maxBit(int x){
  for (int i =31; i>=0; i--){
    if(x&(1LL<<i)){
      return i;
    }
  }
  return 0;
}
//always start with soldier 1
int sol(int numSoldiers){
  int maxr = maxBit(numSoldiers) +1;
  int it = (numSoldiers << 1) -  (1LL<<maxr) +1;
  return it; //soldier that survives
}

int main(){
  int n = 10;
  int res = sol(n);
  show(res);
  return 0;
}
