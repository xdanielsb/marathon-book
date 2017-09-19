#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define magnitude(x) (sqrt(x.f*x.f + x.s*x.s))
#define show(x) cout << #x << " = " << x << endl;
using namespace std;

typedef long double ld;
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
    return min(distance1, distance2);
}
int main(){
    point  A,B,C;
    A = mp(2,4);
    B = mp(5,0);
    C = mp(6,4);
    cout << distance(line(A,B),C);
    return 0;
}
