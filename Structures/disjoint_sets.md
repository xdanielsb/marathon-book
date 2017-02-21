## Disjoint Sets
 - We have n items.
 - Maintains a collection of disjoint sets.
 - Each of the n items is  in exactly one set.
 - Supports two operations efficiently:
    - find(x)
    - union(x)

**Resources:** [Hacker Earth](https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/), [algo.is](https://algo.is/aflv16/aflv_03_data_structures.pdf)

```c++
void initialize(int *arr, int *size, int n) {
    for(int i=0; i<n; i++){
        arr[i] = i;
        size[i] = 1;
    }
}

//Finding the root of an element with path compression.
//If find(arr, i) == find(arr, j) it means that i and j
//are in the same set
int find(int *arr, int i) {
    while(arr[i] != i) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

//Weighted union, for a better running time.
void union(int *arr, int *size, int a, int b) {
    int root_a = find(a);
    int root_b = find(b);

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
```
