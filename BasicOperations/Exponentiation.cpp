#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// (a^b)%c
ll expo(ll a, ll b, ll c){
  if (b == 0) return 1;
  if (b % 2 == 0) {
    ll temp = expo(a, b/2, c);
    return (temp * temp) % c;
  } else {
    ll temp = expo(a, b-1, c);
    return (temp * a) % c;
  }
}
int main(){
  cout << expo(2, 100, 1025);
  return 0;
}
