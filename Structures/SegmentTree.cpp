#include <iostream>
#define left(x) x << 1
#define right(x) x << 1 | 1
#define ROOT 1
using namespace std;

void build(int *T, int *A, int node, int start, int end) {
  if(start == end) {
      T[node] = A[start];
  } else {
      int mid = (start + end) / 2;
      build(T, A, left(node), start, mid);
      build(T, A, right(node), mid + 1, end);
      // Merging the children
      T[node] = T[left(node)] + T[right(node)];
  }
}

void update(int *T, int *A, int node, int start, int end, int i, int val ) {
  if(start == end) {
    A[i] = val;
    T[node] = val;
  } else {
    int mid = (start + end) / 2;
    if(start <= i && i <= mid)
      update(T, A, left(node), start, mid, i, val);
    else
      update(T, A, right(node), mid + 1, end, i, val);
    T[node] = T[left(node)] + T[right(node)];
  }
}

int query(int *T, int node, int start, int end, int a, int b) {
  if(b < start || end < a)  // out of he boundaries
    return 0;
  if(a <= start && end <= b)
    return T[node];
  int mid = (start + end) / 2;
  int p1 = query(T, left(node), start, mid, a, b);
  int p2 = query(T, right(node), mid + 1, end, a, b);
  return p1 + p2;
}
int main() {
  int size = 5;
  int *a = new int[size];
  int *stree = new int[4 * size];
  for (int i = 0;  i < size ; i++) a[i] = i + 1;
  build(stree, a, ROOT, 0, size - 1);
  int from = 0, to = 4;
  cout << query(stree, ROOT, 0, size-1, from, to) << endl;
  return 0;
}
