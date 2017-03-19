#include <bits/stdc++.h>
#define forn(i,j,k) for(int i=j; i<k; i++)
using namespace std;

typedef long long ll;


/*
 * First method 
 * Complexity O(n)
 */

inline ll get_max_sum(ll * data, int size){
    ll maxn =0, aux = 0;
    forn(i, 0, size){
        aux = max(data[i], data[i]+aux);
        maxn = max(maxn, aux);
    }
    return maxn;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int size =8;
    ll *data  = new ll[size];
    
    forn(i, 0, size)
        scanf("%lld", &data[i]);
    /*
    forn(i, 0, size)
        printf("%lld ",data[i]);
    */

    ll res = get_max_sum(data, size);
    printf("The max sum was: %lld \n", res);
    return 0;
}
