#include <bits/stdc++.h>
#define isOdd(x) (x & 0x01)
using namespace std;

void test(int num){
  assert(isOdd(num) == 0);
  cout << "Hello: " << num << endl;
}
int main(){
  int a=10, b=21;
  test(a); test(b);
}
