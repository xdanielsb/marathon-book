#include <iostream>

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)

using namespace std;

int main(){

    forn(_,10){
        cout << "with out variable" << endl;
    }

    int i=0;
    forn(i,10){
        cout << "with variable" << endl;
    }
    return 0;

}
