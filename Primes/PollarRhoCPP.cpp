#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll num;

int modular_pow(ll  base, int exponent, ll  modulus){
	ll result = 1;
	while (exponent > 0){
		if (exponent & 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}
//take care if its' prime infinite loop
ll  PollardRho(ll  n){
	srand (time(NULL));
	if (n==1) return n;
	if (n % 2 == 0) return 2;
	ll  x = (rand()%(n-2))+2;
	ll y = x;
	ll  c = (rand()%(n-1))+1;
	ll d = 1;
	cout << n << endl;
	while (d==1){
		cout << d<<endl;
		x = (modular_pow(x, 2, n) + c + n)%n;
		y = (modular_pow(y, 2, n) + c + n)%n;
		y = (modular_pow(y, 2, n) + c + n)%n;
		d = __gcd(abs(x-y), n);
		if (d==n) return PollardRho(n);
	}
	return d;
}

int main(){
	num = 982451653;
	printf("One of the divisors for %lld is %lld.",num, PollardRho(num));
	return 0;
}
