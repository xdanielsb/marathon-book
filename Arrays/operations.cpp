#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

typedef vector <int > vi;

inline void show(vi &data, int &size){
    for (int i=0; i<size; i++)
            printf("%d \t", data[i]);
        printf("\n");
}

inline void permutation(vi data, int size){
    sort(data.begin(), data.end());
    do {
        show(data, size);
    }while(next_permutation(data.begin(), data.end()));
    show(data, size);
}

int main(){
    int size = 3 ;
    int data[] = {1,4,-1};
    vi vals(begin(data), end(data));
    permutation(vals, size);
    return 0;
}
