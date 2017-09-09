#include<cstdio>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
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
