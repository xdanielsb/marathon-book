#include<iostream>
#include <stdio.h>

using namespace std;

int gcd(int x, int y){
    int g;

    if (x<0) x = -x;
    if (y<0) y = -y;
    if (x+y ==0 ) cerr << "Error" <<endl;

    g=y;
    
    while(x>0){
        g = x;
        x = y % x;
        y = g;
    }

    return g;
}


//n1 != 0 && n2 != 0 
int main(){
    int n1=2366, n2=273;
    printf("gcd= %d ",gcd(n1,n2));
    return 0;
}

