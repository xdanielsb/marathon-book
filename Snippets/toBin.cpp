#include <bits/stdc++.h>
using namespace std;
void toBin(int x){
  for (int i =31; i>=0; --i)
    cout << ((x&(1LL<<i))!=0);
}
int main (){
  toBin(10);
  return 0;
}
