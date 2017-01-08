#include <iostream>


/*
 *It's a pretty good way to evaluate polynomials
 */

/* Example 
 * given the polynomial f(x) = 2x^3 - 6 x^2 - 2x -1
 *  we want to know f(8) 
 *       the traditional form in evaluate it
 *  by the horners method is by syntetic division
 *
 *  8  | X^3 X^2  X^1 X^0
 *     |  2  -6   -2  -1
 *     |      16  80  624
 *     ___________________
 *        2   10  78   623
 *
 * With these we can say that the remainder is 623
 * f(8) = 623
 *
 * Wow a pretty good ALGORITHM
 */


int Horner( int a[], int n, int x ){
    int result = a[n];
    for(int i=n-1; i >= 0 ; --i)
        result = result * x + a[i];
    return result;
}

using namespace std;

int main(){
    int grade = 3;
    
    int a[ grade +1 ] = {-1,-2,-6,2};
    int x = 8;

    cout << Horner (a, grade, x);


    return 0;
}
