#include <stdio.h>

using namespace std;

/*References 
 *http://jwilson.coe.uga.edu/emat6680fa05/schultz/6690/pick/pick_main.htm
 */

typedef double d;

/*
 *b boundary point : a lattice point on the polygon including vertices 
 *i interior point : a lattice points on the polygon's interior region
 */
d area_poligon(d b, d i){
    return (b/2) + i -1;
}

int main(){
    printf("%f",area_poligon(5,5));
    return 0;

}
