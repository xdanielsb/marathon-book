#include <iostream>
#define swap(x,y) (x^=y, y^=x, x^=y)

using namespace std;

int main(){
    int x=324;
    int y=232;
    cout << x << " " << y << endl;
    swap(x,y);
    cout << x << " " << y << endl;
    return 0;
}
