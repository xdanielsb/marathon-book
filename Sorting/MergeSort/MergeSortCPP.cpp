#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void show(int array[], int length_array);
void sort(int array[], int pos_ini, int pos_final);
void merge(int array[], int pos_ini, int pos_mid,int pos_final);



void show(int array [], int length_array){
    int index = 0;
    // cout<< "size : "<< array.size() <<endl;
    while(index<length_array){
        printf("%d ",array[index]);
        index = index +1;
    }
    printf("\n");
}

void sort(int array[], int pos_ini, int pos_final){

    /*In this condition the len of the array
      left and right half arrays will be
      of 1 element both */
    if(pos_final > pos_ini){
         //first calc the half point
        int pos_mid = (pos_ini+pos_final)/2;

        sort(array, pos_ini, pos_mid);
        sort(array, pos_mid +1, pos_final);
        merge(array, pos_ini, pos_mid, pos_final);

    }
}

void merge( int array[], int pos_ini, int pos_mid,int pos_final){


    int size_left = pos_mid - pos_ini + 1;
    int size_right =  pos_final - pos_mid;

    /* create temp arrays */
    int lefthalf[size_left], righthalf[size_right];

    for (int i = 0; i < size_left; i++)
        lefthalf[i] = array[pos_ini + i];
    for (int j = 0; j < size_right; j++)
        righthalf[j] = array[pos_mid + 1+ j];


    int index_right_half  = 0;
    int index_left_half = 0;
    int index = pos_ini;
    while (index_left_half < size_left && index_right_half < size_right) {

        if(lefthalf[index_left_half] <= righthalf[index_right_half]){
            array[index] = lefthalf[index_left_half];
            index_left_half = index_left_half +1;
        }else{
            array[index] = righthalf[index_right_half];
            index_right_half  = index_right_half+1;
        }
        index = index +1;
    }
    //Copy the remaining elements if there is any
    while( index_left_half < size_left){
        array[index] =  lefthalf[index_left_half];
        index_left_half = index_left_half +1;
        index = index +1;
    }
    while( index_right_half < size_right){
        array[index] =  righthalf[index_right_half];
        index_right_half = index_right_half +1;
        index = index +1;
    }
}

int main(){
    int array[] = {-10, 37, 98 , 0 ,12, 192, 5};
    int length_array = sizeof(array)/ sizeof(array[0]);
    show(array, length_array);
    sort(array, 0, length_array  -1);
    show(array, length_array);
}
