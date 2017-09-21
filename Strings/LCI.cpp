#include <bits/stdc++.h>
using namespace std;
//Compute the largest increasing subsequence
int lis( int arr[], int n ){
	int *lis, i, j, max = 0;
	lis = (int*) malloc ( sizeof( int ) * n );
	for (i = 0; i < n; i++ )
		lis[i] = 1;
	for (i = 1; i < n; i++ )
		for (j = 0; j < i; j++ )
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	for (i = 0; i < n; i++ )
		if (max < lis[i])
			max = lis[i];
	free(lis);
	return max;
}
int main(){
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of lis is %d\n", lis( arr, n ) );
	//sol = 10, 22, 33, 50, 60
	return 0;
}
