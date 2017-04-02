#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

typedef set<int> vi;

vi divisores(int n) {
    vi d;
    int r = sqrt(n);

    for(int i = 1; i <= r; i++) {
        if(n % i == 0) {
            d.insert(i);
            d.insert(n / i);
        }
    }
    return d;
}

int main() {
    vi divi = divisores(10);
    for (set<int>::iterator it=divi.begin(); it!=divi.end(); ++it)
        printf("%d ", *it);
    printf("\n");
}
