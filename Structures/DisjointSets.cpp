#include <iostream>
using namespace std;

void initialize(int *arr, int *size, int n) {
    for(int i=0; i<n; i++){
        arr[i] = i;
        size[i] = 1;
    }
}

int find(int *arr, int i) {
    if(arr[i] == i) {
        return i;
    } else {
        arr[i] = find(arr, arr[i]);
        return arr[i];
    }
}

void unite(int *arr, int *size, int a, int b) {
    int root_a = find(arr, a);
    int root_b = find(arr, b);

    if(root_a == root_b)
        return;

    if(size[root_a] < size[root_b]) {
        arr[root_a] = arr[root_b];
        size[root_b] += arr[root_a];
    } else {
        arr[root_b] = arr[root_a];
        size[root_a] += arr[root_b];
    }
}

int main() {}
