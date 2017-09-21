#include <iostream>

using namespace std;

int main(){
    
    double * data;
    data = new double;

    *data = 123.34;

    cout <<  *data << endl;

    delete data;

    return 0;

}
