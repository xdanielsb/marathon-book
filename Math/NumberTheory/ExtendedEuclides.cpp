#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector < ll > vl;

vl arr(3);
/*
	returs gcd(a,b) and find the coeficcients of bezout 
	such that d = ax + by
	arr[0] gcd
	arr[1] x
	arr[2] y
*/
void extended(ll a, ll b){
	ll y =0;
	ll x =1;
	ll xx =0;
	ll yy =1;
	while(b){
		ll	 q = a / b;
		ll t = b;
		b = a%b; 
		a = t;
		
		t = xx;
		xx = x-q*xx;
		x = t;
		
		t = yy;
		yy = y -q*yy;
		y = t;
	}
	arr[0] = a;
	arr[1] = x;
	arr[2] = y;
}
/*

	ax + by  = c
	mcd(a,b) = d
	ax0 + by0 = d 
	c = d * c'
	
	Bezouts identity
	
		X = x0 * c' - (b/d) * k
		Y = y0 * c' + (a/d) * k
		
*/

int main(){
	ll a = 20, b = 50;
	extended(a,b);
	printf("gcd(%lld, %lld) = %lld = %lld * %lld + %lld * %lld\n", a, b, arr[0], a,arr[1], b, arr[2]);
	return 0;
}
