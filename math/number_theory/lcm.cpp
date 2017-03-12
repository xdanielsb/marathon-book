#include <cstdio>
#include "gcd.cpp"

int lcm(int n1, int n2){
    return (n1 * n2) / gcd(n1,n2);
}

// int main(){
//     int n1 = 12, n2 = 5;
//     printf("LCM(%d, %d) = %d\n", n1, n2, lcm(n1,n2));
// }
