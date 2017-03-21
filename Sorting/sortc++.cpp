#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector < ll > vl;
int main(){
    vl data = {234234LL, 2322LL,1LL, -1LL, 3454LL};

    sort(data.begin(), data.end());

    for (int i=0; i< data.size(); i++)
        printf("%lld ", data[i]);
    return 0;
}
