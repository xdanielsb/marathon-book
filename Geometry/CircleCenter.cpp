#include <bits/stdc++.h>

using namespace std;
// Constants
const double PI = acos(-1);
struct point {
    double x;
    double y;
    point (){}
    point (double _x, double _y){
        x = _x;
        y = _y;
    }
};
inline point get_center(point A, point B, point C){

    float yDelta_a = B.y - A.y;
    float xDelta_a = B.x - A.x;
    float yDelta_b = C.y - B.y;
    float xDelta_b = C.x - B.x;

    point center;

    float aSlope = yDelta_a/xDelta_a;
    float bSlope = yDelta_b/xDelta_b; 

    center.x = ( aSlope * bSlope * (A.y - C.y) 
                + bSlope*(A.x + B.x)
                - aSlope*(B.x+C.x) )/(2* (bSlope-aSlope) );

    center.y = -1*(center.x - (A.x+B.x)/2)/aSlope +  (A.y+B.y)/2;

    return center;     
}

