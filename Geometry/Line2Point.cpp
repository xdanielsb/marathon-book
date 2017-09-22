#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define magnitude(x) (sqrt(x.f*x.f + x.s*x.s))
#define show(x) cout << #x << " = " << x << endl;
using namespace std;

typedef  double ld;
typedef pair< ld, ld>  point;
struct line {
  point o, d;
  line(point _o, point _d){
    o = _o;
    d = _d;
  }
};
inline point diff(point o, point d){
    return mp(d.f - o.f, d.s - o.s) ;
}

inline ld crossProduct(point o, point d){
    ld cross  = (o.f * d.s)  - ( o.s * d.f);
    return cross>0? cross: cross *-1;
}
/*
 *Find the  minimun distance from a point to a line
 * just having  two points 'AB' of the line and the point C
 */
ld distance(line l, point C){
    //A, B points in the line
    point A = l.o, B=l.d;
    point AB = diff(A,B); //base
    point AC = diff(A,C);
    ld area = crossProduct(AB, AC);
    ld distance1 = area / magnitude(AB);
    ld distance2 = area / magnitude(AC);
    return mun(distance1, distance2);
}

int main(){
    point  A,B,C;
    A = mp(0,3);
    B = mp(1,2);
    C = mp(2,2);
    printf("%.3lf",distance(line(A,B),C));
    return 0;
}
