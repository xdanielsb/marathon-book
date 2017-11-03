#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long double ld;
typedef pair <ld, ld> point;
typedef vector < point > polygon;
inline  point diff(point o, point d){
  return mp(d.f-o.f, d.s - o.s) ;
}
inline ld crossProduct(point o, point d){
  ld cross  = (o.f * d.s)  - ( o.s * d.f);
  return cross > 0 ? cross :  cross * -1;
}
inline ld area(polygon p){
  int num_points = p.size();
  ld area = 0;
  for (int i = 1; i < num_points -1 ; i++){
    point l1 = diff(p[0],p[i]);
    point l2 = diff(p[0],p[i+1]);
    area += crossProduct(l1,l2);
  }
  return abs(area/2.0);
}
int main(){
  polygon p;
  p.pb(mp(1,0)); p.pb(mp(2,1));
  p.pb(mp(1,2)); p.pb(mp(0,1));
  cout << area(p);
  return 0;
}
