#include <stdio.h>
#include "GCD.c"

/*CALC THE LEAST COMMON DIVISOR
 */
int lcd(int n1, int n2){
    return (n1 * n2) / gcd(n1,n2);
}

/*
int main(){
    int n1 = 2366, n2 = 182;
    printf("LCM= %d\n", lcd(n1,n2));
}
*/
