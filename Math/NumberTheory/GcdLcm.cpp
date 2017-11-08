#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
    if(a == b) return a;
    if(a > b) gcd(a-b, b);
    return gcd(a, b-a);
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
