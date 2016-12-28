#include <iostream>
/* This program computes fibo using 
 * and optimization of the matrix way
 */

/*REFERENCES
 * https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form
 * http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
 */

using namespace std;

const int MAX = 1000;
 
int f[MAX] = {0};
 
int fib(int n){
    if (n == 0)  return 0;
    if (n == 1 || n == 2) return (f[n] = 1);
 
    if (f[n])  return f[n];
    //pretty good way to know if a number is odd or even
    int k = (n & 1)? (n+1)/2 : n/2;
 
    f[n] = (n & 1) ? ( fib(k) * fib(k) + fib(k-1) * fib(k-1) )
           : (2*fib(k-1) + fib(k))*fib(k);
 
    return f[n];
}
 
int main(){
    int n = 9;
    cout<< fib(n);
    return 0;
}
