#include <bits/stdc++.h>
#define isOdd(x) (x & 0x01)
#define debug(x) cout << #x << " = " << x << endl;
#define sz(a) ((int)(a).size())

using namespace std;
void assertt(int num){
  assert(isOdd(num) == 0);
  cout << "Hello: " << num << endl;
}

int main(){
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  assertt(10);
  cout << isOdd(a) << endl;
}
