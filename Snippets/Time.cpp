#include <chrono>
#include <iostream>
using namespace std;
int main(){
  auto start = chrono::high_resolution_clock::now();
  for(long long i = 0; i < 10000000; i++)
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> diff = end-start;
  cout << diff.count() << endl ;
  return 0;
}
