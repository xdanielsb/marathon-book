#include <bits/stdc++.h>
using namespace std;
int main(){
  string needle = "CD", haystack ="MANICD";
  if(haystack.find(needle) != string::npos) cout << "Gotcha!!!";
  else cout << "Not Gotcha";
  cout << endl;
  return 0;
}
