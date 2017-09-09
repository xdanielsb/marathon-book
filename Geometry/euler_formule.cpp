#include <stdio.h>

using namespace std;

typedef long long ll;

b is_a_poligon(ll V, ll E, ll F){
   return V - E + F == 2;
}

int main(){
    printf("%s\n", 
            is_a_poligon(3, 34,5) ? "true" : "false");
    //This is a cube
    printf("%s\n",
            is_a_poligon(8,12,6) ? "true" : "false");
    return 0;
}
