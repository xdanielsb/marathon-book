#include <iostream>
#define isOdd(x) (x & 0x01)

using namespace std;

int main (){
    int a =57;
    int b= 32;
    cout << isOdd(a) << endl;
    cout << isOdd(b) << endl;
    return 0;
}
