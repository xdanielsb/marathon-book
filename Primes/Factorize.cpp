#include <bits/stdc++.h>
#define pb push_back
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
const int MAXN = 1000000;
bool sieve[MAXN + 5];
typedef long long ll;
vector <ll> pri; //primes

void build_sieve(){
  memset(sieve, false, sizeof(sieve));
  sieve[0] = sieve[1] = true;
  for (ll i = 2LL; i * i <= MAXN; i ++){
    if (!sieve[i]){
      for (ll j = i * i; j <= MAXN; j += i){
        sieve[j] = true;
      }
    }
  }
  for (ll i = 2; i <= MAXN; ++i){
    if (!sieve[i]) pri.pb(i);
  }
}
//before call this call build_sieve
vector <ll> fact(long long a){
  vector <ll> ans;
  ll b = a;
  for (int i = 0; 1LL * pri[i] * pri[i] <= a; ++i){
    int p = pri[i];
    while (b % p == 0){
      ans.push_back(p);
      b /= p;
    }
  }
  if (b != 1) ans.push_back(b);
  return ans;
}
int main(){
  build_sieve();
  ll num_to_fact= 128234234LL;
  vector < ll > vll = fact(num_to_fact);
  for (int x=0; x< vll.size(); x++){
    cout << vll[x] << " ";
  }
  cout << endl;
}
