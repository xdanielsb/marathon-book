#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;
/*
 * Verify if a number is prime
 */
bool is_prime(ll n){
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    if (n < 25) return true;
    for(int i = 5; i*i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
int main(){
    cout << is_prime(23234) << endl;
    cout << is_prime(2) << endl;
    cout << is_prime(7454) << endl;
    cout << is_prime(976) << endl;
    cout << is_prime(1973) << endl;
    return 0;

}
