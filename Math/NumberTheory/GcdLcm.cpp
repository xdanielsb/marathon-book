#include<cstdio>
using namespace std;
typedef long long ll;
ll mod( ll a, ll b){
  return (b + (a %b )) %b;
}
ll gcd ( ll a, ll b){
  if (b == 0 ) return a;
  return gcd( b, mod( a , b) );
}
ll lcm(ll n1, ll n2){
    return (n1 *1LL* n2) / gcd(n1,n2);
}
int main(){
    ll n1=2366, n2=273;
    printf("gcd(%ld, %ld) = %ld\n",
            n1, n2, gcd(n1,n2));
    return 0;
}
