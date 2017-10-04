#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modular_pow(ll  base, int exponent, ll  modulus){
 ll result = 1;
 while (exponent > 0){
 /* if y is odd, multiply base with result */
		if (exponent & 1)
			result = (result * base) % modulus;
		/* exponent = exponent/2 */
		exponent = exponent >> 1;
		/* base = base * base */
		base = (base * base) % modulus;
	}
	return result;
}
int main(){
	ll exp = 1023;
	cout << modular_pow (2, exp, 999) << endl;
}
