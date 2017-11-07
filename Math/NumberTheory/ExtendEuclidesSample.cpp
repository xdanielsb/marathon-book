#include<bits/stdc++.h>
#define debug(x) cout << #x << " = "<< x <<endl
using namespace std;
typedef long long ll;
typedef vector <ll > vl;
vl arr(3);
/*
	13250 - Balance Game
*/
//Extended euclidean theorem
void extended(ll a, ll b){
	ll y =0, x =1, xx =0, yy =1;
	while(b){
		ll q = a / b, t = b;
		
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

int main(){
	#ifdef LOCAL
		freopen("in.c", "r", stdin);
	#endif
	ll m, n;
	double a,b,c3;
	
	while(cin >>  m >> n){
		//cout << "Case\n"	;
		cin >> a >> b >> c3;
		extended(a, b);	
		ll mcd = arr[0];
		ll res =0;
		//Debugging purposes
		/*
			debug(mcd);
			printf("%.0f(%d) + %.0f(%d) = %d\n\n\n", a,arr[1], b, arr[2], mcd);
		*/
		for (ll i=-m; i <= m; i++	){		
			ll val = n - c3*i;
			if(val % mcd == 0) {
				ll x0 = arr[1], y0 = arr[2], d = mcd;
				ll cp =  val / mcd;
				//Compute values range kx	 	
				double kminx = (d*(x0*cp -m))/b, kmaxx =  (d*(x0*cp +m))/b;
				//Compute  values range ky
				double kminy = d*(-m -y0*cp)/a, kmaxy = d*(m -y0*cp)/a;
				//Now the intersection betewen kx and ky
				ll kmin = max(ceil(kminx), ceil(kminy));
				ll kmax = min(floor(kmaxx), floor(kmaxy));
				//Add the number of values in the range
				if(kmin<=kmax) res += abs(kmax-kmin)+1;
				//Debugging purposes
				/*
					printf("Cofficient = %d \n", val);
					printf("\tx = %d - %.0fk\n",x0*cp, b/d);
					printf("\ty = %d + %.0fk\n",y0*cp, a/d);
					printf("\tRanges: \n\t\tkx = [%.2f, %.2f]", kminx, kmaxx);
					printf(", ky = [%.2f, %.2f]", kminy, kmaxy);
					printf(", intersection = [%d, %d]\n", kmin, kmax);
					for(int k=kmin; k <=kmax; k++){
						//values of x and y that sattisfy the equation
						int x_ = x0*cp - (b*k)/d ;
						int y_ = y0*cp + (k*a)/d;
					  printf("\tx = %d, y = %d \n",x_ , y_);
					}
					printf("\n\n");
				*/
			}
		}	
		cout << res <<endl;
	}
	return 0;
}
