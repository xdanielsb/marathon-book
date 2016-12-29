#include <iostream>
#include <vector>

using namespace std;

typedef long double ld;
typedef pair <ld, ld> point;
typedef vector < point > polygon;


inline  point r(point o, point d){
    return make_pair(d.first-o.first, d.second - o.second) ;
}

/*Cross product*/
inline ld cross_product(point o, point d){
    ld cross  = (o.first * d.second)  - ( o.second * d.first); 
    return cross > 0 ? cross :  cross * -1;
}

/*
 * find triangles based on  a reference and find the cross product for find the 
 * areas.
 */

inline ld area(polygon p){
    
    int num_points = p.size();
    ld area = 0;
    for (int i = 1; i < num_points -1 ; i++){
        point l1triangle = r(p[0],p[i]);
        point l2triangle = r(p[0],p[i+1]);
        area += cross_product(l1triangle,l2triangle);
    }

    return area < 0 ?( -1 * area)/2:
                     (area/2 );
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    point A, B,C,D;
    A = make_pair(1,0);
    B = make_pair(2,1);
    C = make_pair(1,2); 
    D = make_pair(0,1);

    polygon p(4);
    p[0] = A;
    p[1] = B;
    p[2] = C;
    p[3] = D;

    cout << area(p);


    return 0;

}
