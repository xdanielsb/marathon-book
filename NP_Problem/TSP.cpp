#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define mp make_pair
#define show(x) cout << #x << " = " << x << endl
using namespace std;
typedef vector < int > vi;
typedef vector < bool > vb;
typedef pair <double, double> pdd;
typedef vector < pdd > vpdd;

double dist(pdd _from, pdd _to){
	double res = hypot(_from.f - _to.f, _from.s - _to.s);
	return res;
}

vi tsp(vpdd cities, int n){
	 vi res(n);
	 vb used(n);
	 res [0] = 0;
	 used [0] = true;
	 int best ;
	 for (int i = 1 ; i < n ;i++){
	 		best = -1;
	 		for (int j = 0; j < n ; j++){
	 			if(!used[j]){
	 				if(-1 == best){
		 				best = j;
		 				continue;
					}
		 			double dist1 = dist(cities[res[i-1]], cities[j]);
		 			double dist2 = dist(cities[res[i-1]], cities[best]);
		 			if(dist1 < dist2){
		 				best = j;	
					}	
				}
			}
			res[i] = best;
			used[best] = true;
	 }
	 return res;
}


int main (){
  #ifdef LOCAL
  	freopen("in.c", "r", stdin);
  	//freopen("out.c", "w", stdout);
  #endif 
  int numCities;
  cin >> numCities;
  vpdd cities(numCities);
  double x, y;
  for (int i =0 ; i< numCities; i++){
  	cin >> x >> y ;
  	cities[i]=(mp(x, y));
	}
	vi tour = tsp(cities, numCities);
	for(int c : tour){
		cout << c <<endl;
	}
  return 0;
}