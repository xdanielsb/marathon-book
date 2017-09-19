#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
inline void show(vi &n2){
    for (int i = 0; i < n2.size() ; i++){
        cout << n2[i];
    }
    cout << endl;
}
inline vi sum_arrays(vi &a1, vi &a2){
    int tam = a1.size();
    vi result(tam + 1,0);
    int carry = 0, aux = 0;
    for (int i = tam; i>= 0; i--){
        aux = a1[i] + a2[i]+ carry;
        result[i+1] = aux % 10;
        carry  = aux >= 10 ? 1 : 0;
    }
    result[0] = carry;
    return result;
}

int main(){
    int vals[] = {3,4,1,0,9,8,7,3,4,9,4,3,5,9,2,3,9,0,4,5,8,7,0,2,4,5,2};
    int val2[] = {9,4,1,0,2,8,7,3,4,9,4,3,5,9,2,3,9,0,4,5,8,7,0,2,4,5,2};
    vi n1(begin(vals), end(vals));
    vi n2(begin(val2), end(val2));
    vi result1 = sum_arrays(n1, n2);
    show(result1);
    return 0;
}
