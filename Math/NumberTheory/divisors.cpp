#include <algorithm>
#include <set>
using namespace std;

typedef set<int> si;
/* Get the divisors of a number */
si divisores(int n) {
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
    si divi = divisores(10);
    for (set<int>::iterator it=divi.begin(); it!=divi.end(); ++it)
        printf("%d ", *it);
    printf("\n");
}
