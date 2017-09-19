#include <bits/stdc++.h>
using namespace std;
#define flag(x) printf("[%d]\n", x)
typedef vector<int> vi;
struct fenwick_tree {
    vi data;
    fenwick_tree(int _n) : data(vi(_n + 1, 0)) {}
    void update(int i, int val)  {
        while(i < data.size()) {
            data[i] += val;
            i += i & (-i);
        }
    }
    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += data[i];
            i -= i & (-i);
        }
        return sum;
    }
    int query_segment(int a, int b) {
        return query(b) - query(a - 1);
    }
};
int main() {
    int x[5] = {1, 2, 3, 4, 5};
    fenwick_tree *fq = new fenwick_tree(8);
    for(int i=0; i<5; i++)
        fq->update(i + 1, x[i]);
    //Node 0 -> dummy node
    for(int i=1; i<fq->data.size(); i++) {
        cout << fq->data[i] << ' ';
    }cout << endl;
    //Sum interval [1 - 4]
    flag(fq->query(4));
    //Sum interval [3 - 5]
    flag(fq->query_segment(3, 5));
    return 0;
}
