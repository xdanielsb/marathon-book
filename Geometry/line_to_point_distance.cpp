#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>


using namespace std;

typedef long double ld;

typedef pair< ld, ld>  point;


#define magnitude(x) (sqrt(x.first*x.first + x.second*x.second))


inline  point r(point o, point d){
    return make_pair(d.first-o.first, d.second - o.second) ;
}

/*Cross product*/
inline ld cross_product(point o, point d){
    ld cross  = (o.first * d.second)  - ( o.second * d.first); 
    return cross>0? cross: cross *-1;
}

/*
 *First find cross product 
 */
ld distance(point A, point B, point C){
    //First create vector AB   and AC 
    
    point AB = r(A,B);
    point AC = r(A,C);

    ld cross = cross_product(AB, AC);
    ld distance1 = cross / magnitude(AB);
    ld distance2 = cross / magnitude(AC);

    return min(distance1, distance2);

}

/*
 *Find the distance from the segment AB to C
 */

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    point  A,B,C;

    A = make_pair(0,0);
    B = make_pair(0,2);
    C = make_pair(5,0);

    cout << distance(A,B,C);

    return 0;

}
