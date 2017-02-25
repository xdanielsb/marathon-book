#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void sum(vi a1, vi a2){
    
    int tam = a1.size();
    vi result(tam+1);
    int carry = 0, aux;

    for (int i = tam-1 ; i>= 0 ; i--){
        aux = a1[i] + a2[i]+ carry;
        result[i] = aux % 10;
        carry  = aux = 10;
    }

    for (int i = 0; i<tam -1; i++){
        cout << result[i];
    }
    cout << endl;
    
}

int main(){

    int size = 50;
    vi n1(size,0);
    vi n2(size,0);
    
    n1.push_back(1);
    n1.push_back(3);
    n1.push_back(6);
    n1.push_back(7);
    for (int i = 0; i<n1.size(); i++){
       cout << n1[i];
    }
    cout << endl;

    n2.push_back(3);
    n2.push_back(5);
    n2.push_back(9);
    n2.push_back(0);
    cout << endl;

    for (int i = 0; i<n2.size(); i++){
        cout << n2[i];
    }



    sum(n1, n2);

    return 0;
}
