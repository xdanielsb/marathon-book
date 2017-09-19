#include<bits/stdc++.h>
#define endl '\n'
#define show(x) cout <<#x << " =" <<x <<endl;
using namespace std;
string chars = "0123456789ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

int to10(int n , int b, int pos){
  if (n ==0 ) return 0;
  return ((n % 10)* pow(b,pos)) + to10(n / 10, b, pos+1);
}

string tob(int n, int b){
  if (n == 0) return "";
  return  tob(n / b, b) + chars[n % b];
}
/*
 * ob -> origin base
 * db -> destiny base
 */
string changeBase(int num, int ob, int db){
  if (ob == 10) return tob(num, db);
  return tob(to10(num, ob, 0), db);
}

int main(){
  cout << changeBase(8757,2,16) <<endl;
}
