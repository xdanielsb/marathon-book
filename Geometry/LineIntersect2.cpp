#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef struct point {
    ld x;
    ld y;
} point;
typedef vector < point > vp;
typedef struct line {
  point o, d;
  line (point _o, point _d){
    o=_o;
    d=_d;
  }
}

/*
 * i ---> is the intersection
 */
bool get_line_intersection(point p0, point p1, point p2, point p3){

    ld s1_x, s1_y, s2_x, s2_y;
    point AB, DC;

    AB.x = p1.x - p0.x; AB.y = p1.y -p0.y;
    DC.x = p3.x - p2.x; DC.y = p3.y - p2.y;

    ld s, t;

    s = (-AB.y * (p0.x - p2.x) + AB.x * (p0.y - p2.y))
        / (-DC.x * AB.y + AB.x * DC.y);
    t = ( DC.x * (p0.y - p2.y) - DC.y * (p0.x - p2.x))
        / (-DC.x * AB.y + AB.x * DC.y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1){
        // Collision detected
        point i;
        i.x = p0.x + (t * AB.x);
        i.y = p0.y + (t * AB.y);
        cout << " x = " << i.x << " y= "<< i.y << endl;
        return true;
    }

    return false; // No collision
}


int main(){

    vp p(4);

    line l1({0,1}, {2,3})
    line l2({3,0},{0,3} );

    bool is = get_line_intersection(p[0], p[1], p[2], p[3]);
    printf("%s\n", is ? "Las lineas chocan": " There is not collision");

    return 0;

}
