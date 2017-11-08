#include<iostream>
using namespace std;
/*
  Generate all unique
  partitions of a given integer
*/
void print(int p[], int n){
	for (int i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl;
}

void partitions(int n){
	int p[n];
	int k = 0;
	p[k] = n;

	while (true){
		print(p, k+1);
		// Find the rightmost non-one value in p[]. Also, update the
		// rem_val so that we know how much value can be accommodated
		int rem_val = 0;
		while (k >= 0 && p[k] == 1){
			rem_val += p[k];
			k--;
		}
		// if k < 0, all the values are 1 so there are no more partitions
		if (k < 0) return;
		// Decrease the p[k] found above and adjust the rem_val
		p[k]--;
		rem_val++;
		// If rem_val is more, then the sorted order is violated. Divide
		// rem_val in different values of size p[k] and copy these values at
		// different positions after p[k]
		while (rem_val > p[k]){
			p[k+1] = p[k];
			rem_val = rem_val - p[k];
			k++;
		}
		// Copy rem_val to next position and increment position
		p[k+1] = rem_val;
		k++;
	}
}

// Driver program to test above functions
int main(){
	cout << "All Unique Partitions of 5 \n";
	partitions(5);

	return 0;
}
