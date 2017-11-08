#include <iostream>
using namespace std;
/* Example
 * given the polynomial f(x) = 2x^3 - 6 x^2 - 2x -1
 * we want to know f(8)
 *    -the traditional form in evaluate it
 *  by the horners method is by syntetic division
 *  8  | X^3 X^2  X^1 X^0
 *     |  2  -6   -2  -1
 *     |      16  80  624
 *     ___________________
 *        2   10  78   623
 * With these we can say that the remainder is 623
 * f(8) = 623
 * Wow a pretty good ALGORITHM
 */
typedef long long ll;
ll Horner( ll a[], ll n, ll x ){
  ll result = a[n];
  for(ll i=n-1; i >= 0 ; --i)
    result = result * x + a[i];
  return result;
}
int main(){
  ll grade = 3;
             //-1 -2x -6x^2 +2x^3
  ll a[] = {-1,-2,-6,2};
  ll x = 8;
  cout << Horner (a, grade, x);
  return 0;
}
