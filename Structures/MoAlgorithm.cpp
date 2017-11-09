#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " " <<x <<endl

using namespace std;

int block;

/*
	Complexity O(N*sqrt(N))
*/

struct query {
	int left;
	int right;
	void show(){
		cout <<"["<< left << " "<< right <<"]"<<endl;
	}
	bool operator <(query q) const{ 
		if(left/block == q.left/block ) return right < q.right;
		return left/block < q.left/block;
	}
};



typedef vector < int > vi;
typedef vector < query > vq;

int main(){
	#ifdef LOCAL
		freopen("in", "r", stdin);
	#endif
	int numQueries, numElements;
	//read elements
	cin >> numElements >> numQueries;
	vi arr(numElements);
	for( int i=0; i<numElements; i++){
		cin >> arr[i];
	}
	
	//read queries
	vq qs(numQueries);
	for( int q=0; q<numQueries; q++){
		cin >>  qs[q].left >> qs[q].right;
	}
	
	//calc block size
	block = sqrt(numElements);
	
	//sort queries
	sort(qs.begin(), qs.end());
	
	//iterate over the queries
	int currR = 0, currL =0, sum=0;
	for (query q : qs){
		int l = q.left, r = q.right;
		//remove elements previos range left
		while(currL< l){
			sum -= arr[currL];
			currL++;
		}
		//Add elements in the current range
		while(currL>l){
			sum += arr[currL-1];
			currL--;
		}
		while(currR<=r){
			sum += arr[currR];
			currR++;
		}
		//Remove elemnts previos range right
		while(currR > r+1){
			sum -= arr[currR-1];
			currR--;
		}
		printf("Sum  from [%d, %d]= %d \n", q.left+1, q.right+1, sum);
	}
	
	return 0;
}
