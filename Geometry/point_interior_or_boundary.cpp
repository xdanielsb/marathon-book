#include <iostream>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector> 
#include <math.h>

using namespace std;
/*
 * This script helps to find if a point is inside, outside 
 * or in the boundaries of a poligon
 */

typedef long double ld;

typedef struct point {
    ld x;
    ld y;
}point;

typedef struct vert {
    point o; //origin 
    point d; //destiny
} vert;  

typedef vector < point > verts;

#define magnitude(a) (sqrt(a.x*a.x + a.y*a.y))



/*
 * Check if a point is inside or outside of a figure
 */



/*Cross product*/
inline ld cross_product(point o, point d){
    ld cross  = (o.x * d.y)  - ( o.y * d.x); 
    return cross>0? cross: cross *-1;
}


inline  vert r2(point o, point d){
    return {o, d} ;
}


inline  point r(point o, point d){
    return {d.x-o.x, d.y - o.y} ;
}


ld dist_to_point(point A, point B, point C){
    //First create vector AB   and AC 
    
    point AB = r(A,B);
    point AC = r(A,C);

    ld cross = cross_product(AB, AC);
    ld distance1 = cross / magnitude(AB);
    ld distance2 = cross / magnitude(AC);

    return min(distance1, distance2);

}




/*
 * i ---> is the intersection
 */

bool segments_intersect(vert v0, vert v1){
    
    point p0 = v0.o; 
    point p1 = v0.d; 
    point p2 = v1.o;
    point p3 = v1.d;
    point i;

    ld s1_x, s1_y, s2_x, s2_y;
    point AB, DC;
    
    AB.x = p1.x - p0.x; AB.y = p1.y -p0.y;
    DC.x = p3.x - p2.x; DC.y = p3.y - p2.y;

    ld s, t;

    s = (-AB.y * (p0.x - p2.x) + AB.x * (p0.y - p2.y)) / (-DC.x * AB.y + AB.x * DC.y);
    t = ( DC.x * (p0.y - p2.y) - DC.y * (p0.x - p2.x)) / (-DC.x * AB.y + AB.x * DC.y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1){
        // Collision detected
        i.x = p0.x + (t * AB.x);
        i.y = p0.y + (t * AB.y);
        cout << " x = " << i.x << " y= "<< i.y << endl;
        return true;
    }

    return false; // No collision
}




inline void test_point(verts v, point pun){
    int cant = v.size();

    /*
     * Create a imaginary point to create a ray between the point and it.
     */

    point p;
    int cont = 0; // times that the point intersects
    p.x = rand() % 1000000 + 1;
    p.y = rand() % 1000000 + 1;

    if  ( cant > 0){
        for ( int i= 0 ; i < cant ; i ++ ){
            if (dist_to_point (v[i],v[(i+1)%cant], pun) == 0){
                cout << "The point is in the boundaries"<< endl;
            }
            if (segments_intersect(r2(v[i],v[(i+1)%cant]), r2(pun, p))){
                cont  = cont +1;
            }
        }
    }
    if (cont % 2 == 0){
        cout << "The point is an exterior point " << endl;
    }else {
        cout << "The point is an interior point " << endl;
    }   

}

int main(){

    /*The vertex of the polygon*/
    verts v(4);
    v[0] = {0,2};
    v[1] = {3,5};
    v[2] = {4,3};
    v[3] = {3,0};

    /* Point to check the program */
    
    point p1 = {3,3};
    point p2 = {2,45};

    test_point( v, p1);
    test_point( v, p2);

    return 0;

}
