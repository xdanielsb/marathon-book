#include <bits/stdc++.h>
#define tam 1000
using namespace std;
typedef long long ll;
typedef vector< bool > vbool;
void show (vbool primes){
  ll cap = primes.size();
  for(ll i = 0; i< cap; i++){
    cout << i << " : " << primes[i] << endl;
  }
}
vbool sieve(ll n){
  vbool sieve (tam);
  for (ll i = 0; i < tam; i++)
    sieve[i] = true;
    sieve [0] = sieve[1] = false;
    ll root = sqrt(n);
    for (ll i = 2; i < root; i++){ //find primes
      if(sieve[i]){
        //removes all the multiples
        //of the current prime
        for (ll k = i*1LL*i; k<= n; k+=i){
          sieve[k] = false;
        }
      }
    }
    return sieve;
}
int main(){
    vbool primes = sieve(1000);
    show(primes);;
    primes.clear();
    return 0;
}
