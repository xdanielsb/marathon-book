#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#define show(x) cout << #x << " = " << x << endl;
struct point {
  double x;
  double y;
  point (){}
  point (double _x, double _y){
    x = _x;
    y = _y;
  }
};
inline point getCenter(point p1, point p2, point p3){
  point center;
  float m1 = (p2.y - p1.y)/(p2.x - p1.x);
  float m2 = (p3.y - p2.y)/(p3.x - p2.x);
  center.x = ( m1 * m2 * (p1.y - p3.y) + m2 * ( p1.x + p2.x)
                  - m1 * (p2.x + p3.x) )
              / (2 * (m2 - m1) );
  center.y = -1 * (center.x - (p1.x + p2.x) / 2) / m1 +  (p1.y + p2.y) / 2;
  return center;
}

int main(){
  point p1(1,1), p2(2,4), p3(5,3);
  point res = getCenter(p1, p2, p3);
  show(res.x)
  show(res.y)
  return 0;
}
