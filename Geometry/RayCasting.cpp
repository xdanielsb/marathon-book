#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
/*
 * This program implements the ray casting algorithm to check
 * if a point is inside or outside of a simple polygon
 */
typedef double ld;
struct point {
  ld x, y;
  point(){}
  point(ld x, ld y){
    this->x = x;
    this->y = y;
  }
};
struct vert {
    point o,d;
};
typedef vector < point > polygon;

inline ld cross(point o, point d){ return(o.x * d.y)  - ( o.y * d.x); }
inline ld dot(point o, point d){ return (o.x * d.x)  + ( o.y * d.y); }
inline point diff(point o, point d){ return {d.x-o.x, d.y - o.y} ;}
inline ld dist(point o, point d){ return  sqrt(dot(diff(o,d) , diff(o,d))); }

inline  bool segments_parallel(point a, point b, point c){
    return abs(cross(diff(c,a),diff(b,a)))  == 0;
}
inline bool point_on_segment(polygon v,  point c){
  int cant = v.size();
  for (int i=0;i<cant;i++){
    if (dist(v[i],c)==0) return true;
    if (dist(v[(i+1)%cant],c)==0) return true;
    if(segments_parallel(v[i], v[(i+1)%cant], c) &&
        dot(diff(c,v[i]), diff(c,v[(i+1)%cant])) < 0) {
          return true;
    }
  }
  return false;
}

/* Ray Casting algorithm
 * true inside
 * false outside
 */
bool point_in_polygon(point p, polygon a){
  bool inside = false;
  int cant = a.size();
  for (int i=0;i<cant;i++){
    int j = (i+1) % cant;
    point aux = a[i];
    point nxt = a[j];
    bool cond1 = (p.y < aux.y != p.y < nxt.y);
    bool cond2 = (p.x < aux.x + (nxt.x - aux.x) * (p.y - aux.y) / (nxt.y - aux.y));
    if ( cond1 && cond2 ){
      inside = !inside;
    }
  }
  return inside;
}
inline void test_point(polygon v, point pun){
  if(point_on_segment(v,pun)){
      cout << "on"<<endl;
  }else if (point_in_polygon(pun, v)){
      cout << "in"<<endl;
  }else{
      cout <<"out"<<endl;
  }
}
int main(){
    polygon p;
    p.pb(point(1,0)); p.pb(point(2,1));
    p.pb(point(1,2)); p.pb(point(0,1));
    test_point(p, point(0,0));
    test_point(p, point(1,1));
    test_point(p, point(1.5,0.5));
    return 0;

}
