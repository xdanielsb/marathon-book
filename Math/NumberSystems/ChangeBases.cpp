#include<bits/stdc++.h>
#define endl '\n'
#define show(x) cout <<#x << " =" <<x <<endl;
using namespace std;
typedef long long ll;
string chars = "0123456789ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

ll to10(ll n , ll b, ll mul){
  if (n ==0 ) return 0;
  return (n % 10)*mul + to10(n / 10, b, mul*1LL*b);
}

string tob(ll n, ll b){
  if (n == 0) return "";
  return  tob(n / b, b) + chars[n % b];
}
/*
 * ob -> origin base
 * db -> destiny base
 */
string changeBase(ll num, ll ob, ll db){
  if (ob == 10) return tob(num, db);
  return tob(to10(num, ob, 1LL), db);
}
int main(){
  cout << changeBase(1000,2,10) <<endl;
}
