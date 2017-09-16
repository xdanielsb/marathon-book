#include <bits/stdc++.h>

using namespace std;

const int TAM = 5;
int arr[TAM];

/* Recursive
 * l -> left
 * r -> right
 * x -> element to search
 */
int binary_search(int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l)/2;
        // The element in the middle
        if (arr[mid] == x)  return mid;
        // Smaller of the middle element
        if (arr[mid] > x) return binary_search( l, mid-1, x);
        // Greater that the middle element
        return binary_search(mid+1, r, x);
   }
   return -1;
}

/* Iterative
 * l -> left
 * r -> right
 * x -> element to search
 */
int binary_search_it( int l, int r, int x){
  while (l <= r){
    int m = l + (r-l)/2;
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
 
int main(void){
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 4;
    arr[3] = 10;
    arr[4] = 40;
   int x = 10;
   int result = binary_search_it(0, TAM-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d \n", result);
   return 0;
}
