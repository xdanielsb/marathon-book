// C++ program Miller-Rabin primality test
#include <bits/stdc++.h>
using namespace std;

int power(long long x, unsigned long long y, long p){
	int res = 1;	 // Initialize result
	x = x % p; // Update x if it is more than or
				// equal to p
	while (y > 0){
		if (y & 1)
			res = (res*x) % p;
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}

bool miillerTest(long long d, long n){
	long long a = 2 + rand() % (n - 4);

	long long  x = (long long)power(a, d, n);

	if (x == 1 || x == n-1)
	return true;
	while (d != n-1){
		x = (long long)(x * x) % n;
		d *= 2;
		if (x == 1)	 return false;
		if (x == n-1) return true;
	}

	return false;
}
bool isPrime(long long n, long long k){
	// Corner cases
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	// Find r such that n = 2^d * r + 1 for some r >= 1
	long long d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterate given nber of 'k' times
	for (long i = 0; i < k; i++)
		if (miillerTest(d, n) == false)
			return false;

	return true;
}

// Driver program
int main(){
	long k = 4; // Number of iterations

	long long n = 982451653;
	cout << isPrime(n, k) << endl;

	return 0;
}

