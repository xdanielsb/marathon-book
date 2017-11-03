#include <iostream>
using namespace std;
typedef long long ll;
ll  *f;
/*REFERENCES
 * https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form
 * http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
 */
int fib(ll n){
    if (n == 0)  return 0;
    if (n == 1 || n == 2) return (f[n] = 1);
    if (f[n])  return f[n];
    int k = (n & 1)? (n+1)/2 : n/2;
    if (n&1){
      f[n] = (ll) fib(k) * fib(k) + fib(k-1) * fib(k-1) ;
    }else{
      f[n] = (2*fib(k-1) + fib(k))*fib(k);
    }
    return f[n];
}

int main(){
    ll n = 10;
    f = new ll[n];
    cout<< fib(n);
    return 0;
}
