// lower_bound/upper_bound example
#include <iostream>     // cout
#include <algorithm>    // lower_bound, upper_bound, sort
#include <vector>       // vector
using namespace std;
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  vector<int>::iterator low,up;
  low=lower_bound (v.begin(), v.end(), 20); //          ^
  up= upper_bound (v.begin(), v.end(), 20); //                   ^

  cout << "lower_bound at position " << (low- v.begin()) << '\n';
  cout << "upper_bound at position " << (up - v.begin()) << '\n';
  /*
lower_bound at position 3
upper_bound at position 6
   * 

  return 0;
}
