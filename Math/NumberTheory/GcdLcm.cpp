#include<cstdio>
using namespace std;
int gcd(int a, int b){
    if(a == b) return a;
    if(a > b) gcd(a-b, b);
    return gcd(a, b-a);
}
int lcm(int n1, int n2){
    return (n1 * n2) / gcd(n1,n2);
}
int main(){
    int n1=2366, n2=273;
    printf("gcd(%ld, %ld) = %ld\n",
            n1, n2, gcd(n1,n2));
    return 0;
}
