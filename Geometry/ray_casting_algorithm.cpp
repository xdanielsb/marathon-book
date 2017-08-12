#include <iostream>
#include <algorithm>
#include <vector> 
#include <math.h>

using namespace std;

/*
 * This program implements the ray casting algorithm for find 
 * if a point is inside or outside of a simple polygon
 *
 * References
 * (https://en.wikipedia.org/wiki/Even%E2%80%93odd_rule)
 */

typedef double ld;

typedef struct point {
    ld x;
    ld y;
}point;

typedef struct vert {
    point o; //origin 
    point d; //destiny
} vert;  

typedef vector < point > verts;


/*Cross product*/
inline ld cross(point o, point d){ return(o.x * d.y)  - ( o.y * d.x); }
inline ld dot(point o, point d){ return (o.x * d.x)  + ( o.y * d.y); }
inline point r(point o, point d){ return {d.x-o.x, d.y - o.y} ;} 
inline ld dist(point o, point d){ return  sqrt(dot(r(o,d) , r(o,d))); }

inline  bool segments_parallel(point a, point b, point c){ 
    return abs(cross(r(c,a),r(b,a)))  == 0;
}

/*
 * Test if a point is over a segment
 */
inline bool point_on_segment(verts v,  point c){
    //First create vector AB   and AC 
    int cant = v.size();
    for (int i=0;i<cant;i++){
        if (dist(v[i],c)==0) return true;
        if (dist(v[(i+1)%cant],c)==0) return true;
        if(segments_parallel(v[i], v[(i+1)%cant], c) && 
                dot(r(c,v[i]), r(c,v[(i+1)%cant])) < 0) {
                return true;
        }
    }
    return false;
}

/* Ray Casting algorithm 
 * true inside
 * false outside
 */ 
 
bool point_in_polygon(point p, verts a){
    bool inside = false;
    int cant = a.size();
    for (int i=0;i<cant;i++){
        int j = (i+1) % cant;
        if ( (p.y < a[i].y != p.y < a[j].y) && 
             (p.x < a[i].x + 
               (a[j].x-a[i].x) *
                (p.y-a[i].y) /
               (a[j].y-a[i].y)) 
            ){
            inside = !inside;
        }
    }
    return inside;
}


inline void test_point(verts v, point pun){

    if(point_on_segment(v,pun)){
        cout << "on"<<endl;
    }else if (point_in_polygon(pun, v)){
        cout << "in"<<endl;
    }else{
        cout <<"out"<<endl;
    }

}

int main(){

    /*The vertex of the polygon*/
    int num_points, num_test;
    ld x,y;

    cin >> num_points;
    do{
        verts v(num_points);
        //read points
        for (int i=0 ; i< num_points; i++){
            cin >> x>>y;     
            v[i] = {x,y};
        }

        cin >> num_test;
        // Point to check the program 
        for (int i=0 ; i< num_test; i++){
            cin >> x>>y;
            point p = {x,y};
            test_point( v, p);
        }

        cin >> num_points;
    } while(num_points != 0);

    return 0;

}


