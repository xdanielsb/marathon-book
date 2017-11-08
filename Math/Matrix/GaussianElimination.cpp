#include<bits/stdc++.h>
using namespace std;
int static N = 3;
double **mat;

void swap_row(int i, int j){
	for (int k=0; k<=N; k++){
		double temp = mat[i][k];
		mat[i][k] = mat[j][k];
		mat[j][k] = temp;
	}
}
void backSub(){
	double x[N]; // An array to store solution
	for (int i = N-1; i >= 0; i--){
		x[i] = mat[i][N];
		for (int j=i+1; j<N; j++){
			x[i] -= mat[i][j]*x[j];
		}
		x[i] = x[i]/mat[i][i];
	}
	printf("\nSolution for the system:\n");
	for (int i=0; i<N; i++)
		printf("X%d= %lf\n", i, x[i]);
}
int forwardElim(){
	for (int k=0; k<N; k++){
		int i_max = k;
		int v_max = mat[i_max][k];
		for (int i = k+1; i < N; i++)
			if (abs(mat[i][k]) > v_max)
				v_max = mat[i][k], i_max = i;
		if (!mat[k][i_max])
			return k; // Matrix is singular
		if (i_max != k)
			swap_row(k, i_max);

		for (int i=k+1; i<N; i++){
			double f = mat[i][k]/mat[k][k];
			for (int j=k+1; j<=N; j++)
				mat[i][j] -= mat[k][j]*f;
			mat[i][k] = 0;
		}
	}
	return -1;
}
void gaussianElimination(){
	int singular_flag = forwardElim();
	if (singular_flag != -1){
		printf("Singular Matrix.\n");
		if (mat[singular_flag][N])
			printf("Inconsistent System.");
		else
			printf("May have infinitely many "
				"solutions.");
		return;
	}
	backSub();
}

int main(){
	//The last column represents the coefficients
	//input matrix.in
	/*
		3
		3.0 2.0 -4.0 3.0
		2.0 3.0 3.0 15.0
		5.0 -3 1.0 14.0
	*/
	cin >> N;
	mat = new double*[N];
	for (int i =0; i <=N; i++){
		mat[i] = new double[N+1];
	}
	for (int row=0; row<N; row++)
		for ( int col=0; col<=N;col++)
			cin >> mat[row][col];

	gaussianElimination();
	return 0;
}
