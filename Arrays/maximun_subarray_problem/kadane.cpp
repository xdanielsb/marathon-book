#include <bits/stdc++.h>
#define forn(i,j,k) for(int i=j; i<k; i++)
using namespace std;

typedef long long ll;

/*
 * Largest Sum Contiguous Subarray
 * Kadane Algorithm
 * Complexity O(n)
 */

inline ll get_max_sum(ll * data, int size){
    ll maxn = data[0], aux = data[0];
    forn(i, 1, size){
        aux = max(data[i], data[i] + aux);
        maxn = max(maxn, aux);
    }
    return maxn;
}

int main(){
    //Faster input and output
    ios::sync_with_stdio(false);
    cin.tie(0);

    int size = 8;
    ll *data  = new ll[size];

    forn(i, 0, size)
        scanf("%lld", &data[i]);

    ll res = get_max_sum(data, size);
    printf("The max that can be done with \
            Contiguous elements isin the array: %lld \n", res);

    return 0;
}
