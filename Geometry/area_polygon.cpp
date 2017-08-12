#include <iostream>
#include <vector>
#define f first
#define s s

using namespace std;

typedef long double ld;
typedef pair <ld, ld> point;
typedef vector < point > polygon;

inline  point r(point o, point d){
    return make_pair(d.f-o.f, d.s - o.s) ;
}

inline ld cross_product(point o, point d){
    ld cross  = (o.f * d.s)  - ( o.s * d.f);
    return cross > 0 ? cross :  cross * -1;
}

inline ld area(polygon p){

    int num_points = p.size();
    ld area = 0;
    for (int i = 1; i < num_points -1 ; i++){
        point l1 = r(p[0],p[i]);
        point l2 = r(p[0],p[i+1]);
        area += cross_product(l1,l2);
    }
    return area < 0 ?( -1 * area)/2:
                     (area/2 );
}

int main(){
    //Fast input and output
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    point A, B, C, D;
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
