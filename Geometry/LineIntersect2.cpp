#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;
#define show(x) cout << #x << " = " << x << endl;
typedef long double ld;
struct point {
  ld x;
  ld y;
  point (){}
  point (int _x, int _y){
    x = _x;
    y = _y;
  }
};
typedef vector < point > vp;
struct line {
  point o, d;
  line(){}
  line (point _o, point _d){
    o=_o;
    d=_d;
  }
};

pair < bool, point> getLineIntersection(line l1, line l2){
  point p0 =l1.o, p1=l1.d, p2=l2.o, p3=l2.d;
  point AB( p1.x - p0.x, p1.y -p0.y);
  point DC( p3.x - p2.x, p3.y - p2.y);

  ld s, t;
  point i;

  int dx = p0.x - p2.x;
  int dy = p0.y - p2.y;
  s = (-AB.y * dx + AB.x * dy) / (-DC.x * AB.y + AB.x * DC.y);
  t = ( DC.x * dy - DC.y * dx) / (-DC.x * AB.y + AB.x * DC.y);

  if (s >= 0 && s <= 1 && t >= 0 && t <= 1){
    // Collision detected
    i.x = p0.x + (t * AB.x);
    i.y = p0.y + (t * AB.y);
    return mp(true, i);
  }
  return mp(false, i); // No collision
}

int main(){
    line l1(point(0,1),point(2,3));
    line l2(point(3,0),point(0,3));
    pair<bool, point> i = getLineIntersection(l1,l2);
    // intersect x=1, y=2
    if (i.f){
      printf("The lines does collide in: \n");
      show(i.s.x);
      show(i.s.y);
    }else {
      printf("There is no collision.\n");
    }
    return 0;
}
