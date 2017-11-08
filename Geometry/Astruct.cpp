#include <bits/stdc++.h>
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)
#define debug(x) cout << #x << " " << x << endl;

using namespace std;

struct point {
  double x, y;
  point() {}
  point(double _x, double _y){
    x = _x;
    y = _y;
  }
  point operator + (point p) const { return point(p.x + x, p.y +y);  }
  point operator - (point p) const { return point(x - p.x, y -p.y);  }
  point operator *(double d) const { return point(x*d, y*d); }
  bool operator ==(point p) const { return p.x == x && p.y==y; }
  double dot(point p) { return x*p.x + y*p.y;};
  double cross2(point p) { return x*p.y - p.x*y;};
  double mag () {return sqrt(x*x + y*y);};
  double norm() {return x*x + y*y;};
  double dist(point p2){return hypot(x - p2.x, y - p2.y); };
  void show(){ printf("x= %lf, y=%lf\n", x, y);}
};

struct line {
  point o;//origin
  point d;//destiny
  double m;
  line (){}
  line( point _o, point _d){
    o = _o;
    d = _d;
  }
  double slope(){
    if (o.x != d.x){
      m = (double)(d.y - o.y) / (double)(d.x - o.x);
      return m;
    }
    m = INF;
    return INF;
  }

};
double cross(point &o, point &a, point &b) {
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool areParallel(line l1, line l2) {
  return fabs(l1.slope()-l2.slope())<EPS ;
}
double distToLine(point p, line l1) {
  // formula: c = a + u * ab
  point a = l1.o, b = l1.d, c;
  point ap = p-a, ab = b-a;
  double u = ap.dot(ab) / ab.norm();
  c = a + ab*u;
  return c.dist(p);
}

double distToSegment(point p, line l1) {
  point a = l1.o, b = l1.d, c;
  point ap = p-a, ab = b-a;
  double u = ap.dot(ab) / ab.norm();
  if (u < 0.0) {
    c = point(a.x, a.y);  // closer to a
    return p.dist(a);
  }
  if (u > 1.0) {
    c = point(b.x, b.y);  // closer to b
    return p.dist(b);
  }
  return distToLine(p, line(a, b));
}

int main(){
  point a(0,4);
  point b(5,0);
  point c(7,0);
  a.show();
  b.show();
  c.show();
  line l1(a,b), l2(a,c);
  cout << "m1= "<< l1.slope() << endl;
  cout << "m2= "<< l2.slope() << endl;
  cout << "parallel l1 || l2? = " << (areParallel(l1, l2)?"true": "false") << endl;
  cout << "dist from point to line= " << distToLine(c, l1) << endl;
  cout << "dist from point to segment= " << distToSegment(c, l1) << endl;
  return 0;
}
