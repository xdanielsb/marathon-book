#include <bits/stdc++.h>
#define forn(i,j,k) for(int i=j; i<k; i++)
using namespace std;
typedef long long ll;
/*
 * Largest Sum Contiguous Subarray
 * Kadane Algorithm
 * Complexity O(n)
 */
inline ll get_max_sum(ll data[8], int size){
  ll max_so_far= data[0];
  ll max_ending_here = data[0];
  forn(i, 1, size){
    max_ending_here = max(data[i], \
    data[i] + max_ending_here);
    max_so_far = max(max_so_far, max_ending_here);
  }
  return max_so_far;
}
int main(){
  int size = 8;
  ll data[8] = {-1,2,4,-3,5,2,-5,2};
  ll res = get_max_sum(data, size);
  printf("The max sum that can be done with \n \
    Contiguous elements is: %lld \n", res);
  return 0;
}
