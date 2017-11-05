#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int x){
  int s = sqrt(x);
  return (s*s == x);
}
bool isFibonacci(int n){
    // n is Fibinacci if one of 5*n*n + 4 or 5*n*n - 4 or both
    // is a perferct square, this is deduced of the discriminant
    //of binnets formule
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);
}
 
// A utility function to test above functions
int main() {
  for (int i = 1; i <= 10; i++)
     isFibonacci(i)? cout << i << " is a Fibonacci Number \n":
                     cout << i << " is a not Fibonacci Number \n" ;
  return 0;
}
