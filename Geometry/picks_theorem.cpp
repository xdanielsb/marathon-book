#include <stdio.h>

using namespace std;

/*
 *  Pick's theorem is a useful method for determining the area of any polygon whose
 *  vertices are points on a lattice, a regularly spaced array of points.
 */

typedef double d;

/*
 * b boundary point : a lattice point on the polygon including vertices
 * i interior point : a lattice points on the polygon's interior region
 */
d area_poligon(d b, d i){
    return (b/2) + i -1;
}

int main(){
    printf("%f",area_poligon(5,5));
    return 0;
}
