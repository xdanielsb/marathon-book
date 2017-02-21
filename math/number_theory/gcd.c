#include<stdio.h>

/* CALC GREATEST COMMON DIVISOR BY EUCLIDES ALGORITHM
 * r -> remainder
 * q -> quotient
 */
int calc_gcd(int n1, int n2, int r, int q){
    if (r == 0)
        return n2;
    return calc_gcd(n2,r,n2 % r, n2 / r);
}

/* FIRE UP THE FUNCTION GCD
 */
int gcd(int n1, int n2){
    if ( n1 > n2 )
        return calc_gcd(n1, n2, n1 % n2, n1 / n2);
    return calc_gcd(n2, n1, n2 % n1, n2 / n1);
}

/*
int main(){
    int n1=2366, n2=273;
    printf("gcd= %d ",gcd(n1,n2));
    return 0;
}
*/
