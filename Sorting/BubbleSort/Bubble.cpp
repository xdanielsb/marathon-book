#include <bits/stdc++.h>
#define forn(i,j,k) for (int i=j; i<k; i++)
using namespace std;
typedef long long ll;
inline void sort(ll *arr, int size){
  forn(i,0,size-1)
    forn(j,0, size-i-1)
      if (arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
}
int main(){
    int size =8;
    ll *data  = new ll[size];
    forn(i, 0, size) scanf("%lld", &data[i]);
    sort(data, size);
    forn(i, 0, size) printf("%lld ",data[i]);
    return 0;
}
