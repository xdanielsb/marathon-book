#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

typedef vector<int> vi;

void sum(vi a1, vi a2){
    
    int tam1 = a1.size();
    int tam2 = a2.size();
    int tam3 = tam1 >= tam2 ? tam1 : tam2;

    vi result(tam3 + 1, 0);

    int carry = 0, aux;

    for (int i = tam3-1 ; i>= 0 ; i--){
       // cout << "n1 =" << a1[i] << " n2 =" << a2[i] << " carry= " << carry << endl;
        aux = a1[i] + a2[i]+ carry;
        result[i] = aux % 10;
        carry  = aux >= 10 ? 1 : 0; 
    }

    cout << "result: " <<endl;
    for (int i = 0; i<tam3 ; i++){
        cout << result[i];
    }
    cout << endl;
    
}

int main(){

    int vals[] = {2,3,4,1,0,9,8,7,3,4,9,4,3,5,9,2,3,9,0,4,5,8,7,0,2,4,5,2,4,5,8,7,2,0,9,4,5,7,8,2,0,4,9,5,8,7,2,0,4,5,8,7,2,0,4,5,8,2,7,9,0,5,2,4,7,2,4,5,7,2,0,9,4,5,8,7,2,0,9,4,5,8,7,2};
    int val2[] = {2,3,4,1,0,9,8,7,3,4,9,4,3,5,9,2,3,9,0,4,5,8,7,0,2,4,5,2,4,5,8,7,2,0,9,4,5,7,8,2,0,4,9,5,8,7,2,0,4,5,8,7,2,0,4,5,8,2,7,9,0,5,2,4,7,2,4,5,7,2,0,9,4,5,8,7,2,0,9,4,5,8,7,2};
    
    vi n1(begin(vals), end(vals));
    vi n2(begin(val2), end(val2));
    
    for (int i = 0; i<n1.size(); i++){
       cout << n1[i];
    }
    cout << endl;

   
    for (int i = 0; i<n2.size(); i++){
        cout << n2[i];
    }
    cout << endl;


    sum(n1, n2);

    return 0;
}
