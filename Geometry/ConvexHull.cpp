#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
/* CONVEX HULL: Minimun Convex Polygon
 * Convex hull is the smallest set of points that containss tho set X.
 */



/*
 * Steps for the algorithm
 * 1- loop through all of the points and find the most left point
 *    if there is a tie, pick the highest point
 * 2- from the most left we are going to use cross product for finding
 *    the further clockwise from the current possition
 * 3- If there is no colinear points the code is straighforward.
 */

typedef long double ld;
const ld INF = 9000000000000000000;
typedef struct point {
    ld x;
    ld y;
} point;

typedef vector< point > points;
#define magnitud(p) (sqrt(p.x * p.x + p.y * p.y))
#define crossproduct(a,b) (a.x * b.y - a.y * b.x)
#define dist(a,b) (sqrt(pow((b.x - a.x),2) + pow((b.y * a.y),2)))
/*
 * Return the index of the most left point
 */
inline int left_most(points p){
    int cant = p.size();
    if(cant > 0){

        int ref = 0;
        for( int i = 1; i < cant; i++){
            if (p[i].x < p[ref].x ){
                ref = i;
            }
        }
        return ref;
    }
    return -1;
}

/* Create a vector based on two points
 */
inline point cv(point a, point b){
    return {b.x - a.x, b.y - a.y};
}

/*
 * lm -> stands out the left most point
 * more_points -> if is true use as many points as possible
 *                for the convex hull otherwise use as few
 *                as possible
 */
inline void convex_hull(points p, int lm, bool more_points){
    int cant = p.size();

    vector< bool > used (cant, false);
    /*
     * Just to clarify
     */
    int start = lm;


    do
    {
        int n = -1;
        ld dist = more_points?INF:0;


        cout << "Left most is " << lm << ": x= " << p[lm].x << " y= "<< p[lm].y << endl;

        for (int i = 0; i < cant ; i ++){

            //Do not go back to the same point
            if (i == lm) continue;

            //Do not reuse
            if(used[i])continue;


            //Set N
            if ( n==-1) {
                n =i;

                continue; //if I do not put this continue, the
                          //program will do a cross product
                          //with the same line
            }

            ld cross = crossproduct(cv(p[i],p[lm]), cv(p[n],p[lm]));
            ld d = dist(p[i], p[lm]);
            if (cross < 0 ){ //This is the magic
                n = i;
                dist = d;
            }else if (cross == 0){
                //In this case, both N and X are in the
                //same direction.  If more_points is true, pick the
                //closest one, otherwise pick the farthest one.
                if(more_points && d < dist){
                    dist = d;
                    n = i;
                }else if(!more_points && d > dist){
                    dist = d;
                    n = i;
                }
            }

        }

        lm = n; //change the most left;
        used[lm] = true;
    }while(start != lm);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    points p(6);

    p[0] = {0,2};
    p[1] = {3,5};
    p[2] = {4,3};
    p[3] = {3,0};
    p[4] = {3,3};
    p[5] = {4,6};
    convex_hull(p, left_most(p), false);

    return 0;

}
