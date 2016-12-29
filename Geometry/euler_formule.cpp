#include <stdio.h>

using namespace std;

/*REFERENCES
 * http://www.mathsisfun.com/geometry/eulers-formula.html
 *
 * Test a program if fullfil with Euler's formula
 */

typedef bool b;
typedef long long ll;

b is_a_poligon(ll V, ll E, ll F){
   return V - E + F == 2;
}

int main(){
    printf("%s\n", is_a_poligon(3, 34,5) ? "true" : "false");
    //This is a cube
    printf("%s\n",is_a_poligon(8,12,6) ? "true" : "false");

    return 0;
}

