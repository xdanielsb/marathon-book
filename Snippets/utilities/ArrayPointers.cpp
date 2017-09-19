#include <iostream>

using namespace std;

inline void example_1(){
    char * name;
    name = new char[10];
    delete [] name;
}

inline void example_2(){
    int row = 4;
    int col = 3;
    
    //Allocate memory for rows 
    double **pvalue  = new  double* [row];
    //Now allocate memory for columns
    for (int i=0; i<col; i++){
        pvalue[i] = new double[col];
    }


    //Now release memory 
    for(int i = 0; i < row; i++) {
        delete [] pvalue[i]; 
    }
    delete [] pvalue; 
}

int main(){
    example_1();
    example_2();

 
    return 0;

}


