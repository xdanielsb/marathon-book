#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPrime(ll n){
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  if (n < 25) return true;
  for(int i = 5; i*i <= n; i += 6){
    if(n % i == 0 || n % (i + 2) == 0)
        return false;
  }
  return true;
}
int main(){
    cout << isPrime(23234) << endl;
    cout << isPrime(2) << endl;
    cout << isPrime(7454) << endl;
    cout << isPrime(976) << endl;
    cout << isPrime(1973) << endl;
    return 0;
}
