#include <iostream>

using namespace std;

void show(int array[], int length_array);
void sort(int array[], int length_array);

void show(int array[], int length_array){
    for (int index = 0; index < length_array; index ++)
        cout << array[index] << " ";
    cout<< endl;
}


void sort(int array[], int length_array){
    for (int index = 1; index < length_array; index ++){
        int key = array[index];
        int index_aux = index - 1;
        while (index_aux >= 0 && array[index_aux] > key){
            array[index_aux + 1 ] = array[index_aux];
            index_aux = index_aux -1;
        }
        array[index_aux + 1] = key;
    }
}

int main(){
    int length_array = 8;
    int array[]  = {50, 885, 1 , -8 , 54 , 2, 54, 0};
    show(array, length_array);
    sort(array, length_array);
    show(array, length_array);
}
