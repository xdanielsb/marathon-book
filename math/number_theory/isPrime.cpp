#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;


bool is_prime(ll n){
    if (n<=1) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    ll root = sqrt(n);
    for (int i=3; i<= root; i+=2){
        if(n%i == 0 )
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
