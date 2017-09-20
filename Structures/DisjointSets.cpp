#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
struct union_find {
  vi data, pe;
  union_find(int n) : data(vi(n)), pe(vi(n)) {
    for(int i=0; i<data.size(); i++)
      data[i] = i;
  }
  int find(int x) {
    if(x == data[x]) return x;
    data[x] = find(data[x]);
    return data[x];
  }
  bool unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px == py) return false;
    if(pe[px] > pe[py]) swap(px, py);
    pe[px] += pe[py];
    data[py] = px;
    return true;
  }
};
int main() {
    union_find uf(10);
    uf.unite(0, 2);
    cout << uf.find(0) << endl;
    cout << uf.find(2) << endl;
    assert(uf.find(0) == uf.find(2));
    assert(uf.find(0) != uf.find(1));
    return 0;
}
