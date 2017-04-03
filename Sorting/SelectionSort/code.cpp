#include<iostream>
using namespace std;

int show(int array[], int length_array);
int sort(int array[], int length_array);


int show(int array[], int length_array){
    for (int index = 0 ; index < length_array; index++)
        cout << array[index] << " ";
    cout << endl;

}

int sort(int array[], int length_array){
    for (int index = 0; index < length_array; index++){
        int pos_smallest = index;
        for(int index_aux = index+1; index_aux < length_array; index_aux++){
            if (array[pos_smallest] > array[index_aux]){
                pos_smallest = index_aux;
            }
        }
        //Swap
        if( pos_smallest != index){
            int aux = array[index];
            array[index] = array[pos_smallest];
            array[pos_smallest] = aux;
        }
    }

}

int main(){
    int length_array = 7;
    int array [] = {58, -5, 10, 8, 78 ,234, 43};

    cout << "Original Array" << endl;
    show(array, length_array);

    sort(array, length_array);

    cout << "Sorted Array" << endl;
    show(array, length_array);
}
