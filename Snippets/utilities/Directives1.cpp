#include <iostream>
using namespace std;
#define concat(a, b) a ## b

int main() {
   int xy = 100;
   cout << concat(x, y);
   return 0;
}
