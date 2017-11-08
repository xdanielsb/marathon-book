#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TAM = 5;
ll arr[TAM];
/* Recursive
 * l -> left
 * r -> right
 * x -> element to search
 */
ll binarySearchRec(ll l, ll r, ll x){
  if (r >= l){
    ll mid = l + (r - l)/2;
    // The element in the middle
    if (arr[mid] == x)  return mid;
    // Smaller of the middle element
    if (arr[mid] > x) return binarySearchRec( l, mid-1, x);
    // Greater that the middle element
    return binarySearchRec(mid+1, r, x);
  }
 return -1;
}

/* Iterative
 * l -> left
 * r -> right
 * x -> element to search
 */
ll binarySearchIte( ll l, ll r, ll x){
  while (l <= r){
    ll m = l + (r-l)/2;
    // The element in the middle
    if (arr[m] == x)  return m;
    // Smaller of the middle element
    if (arr[m] < x)  l = m + 1;
    // Greater that the middle element
    else r = m - 1;
  }
  // if we reach here, then element was not present
  return -1;
}

int main(){
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 4;
    arr[3] = 10;
    arr[4] = 40;
   ll x = 10;
   ll result = binarySearchIte(0, TAM-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d \n", result);
   return 0;
}
