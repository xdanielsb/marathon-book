#include <iostream>
#include <assert.h>
#define isOdd(x) (x & 0x01)
using namespace std;

void test(int num){
    assert(isOdd(num) == 0);
    cout << "Hello: " << num << endl;
}

int main(){
    int a=10, b=22, c=23, d=32;
    test(a);
    test(b);
    test(c);
    test(d);
}
