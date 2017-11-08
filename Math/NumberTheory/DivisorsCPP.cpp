#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef set<ll> si;
/* Get the divisors of a number */
si divisores(ll n) {
  si d;
  ll r = sqrt(n);
  for(ll i = 1; i <= r; i++) {
    if(n % i == 0) {
      d.insert(i);
      d.insert(n / i);
    }
  }
  return d;
}
int main() {
  si divi = divisores(10);
  for(ll el: divi){
  	cout << el <<endl;
	}
  printf("\n");
}
