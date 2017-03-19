#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;

vi divisores(int n) {
    vi d;
    int r = sqrt(n);

    for(int i = 1; i <= r; i++) {
        if(n % i == 0) {
            d.push_back(i);

            if(i != r)
                d.push_back(n / i);
        }
    }
    return d;
}

int main() {
    vi divi = divisores(52132);
    for(int i=0; i<divi.size(); i++)
        printf("%d ", divi[i]);
    printf("\n");
}
