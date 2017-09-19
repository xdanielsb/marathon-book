#include<iostream>

using std::cout;
using std::cin;
using std::endl;


/*
 * g++ -E test.cpp  > sal.out
 * compile with that command and see how the compiler replace the constant
 */
#define PI 3.141516
#define MIN(a,b) (((a)<(b)) ? a : b)

int main(){

    cout << "The number PI is " << PI << endl;
    cout <<"The minimum is " << MIN(i, j) << endl;
    return 0;

}
