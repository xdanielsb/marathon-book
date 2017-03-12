#include<cstdio>
using namespace std;

typedef long long ll;

int gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int n1=2366, n2=273;
    printf("gcd(%ld, %ld) = %ld\n", n1, n2, gcd(n1,n2));
    return 0;
}
