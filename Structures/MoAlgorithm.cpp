#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " " <<x <<endl
#define MAX (1000005)
using namespace std;

int block;
int cnt[MAX];

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

int numDiff =0;
vi arr;


void add(int pos){
	numDiff += arr[pos];
}

void remove(int pos){
	numDiff -= arr[pos];
}


int main(){
	#ifdef LOCAL
		freopen("in.c", "r", stdin);
	#endif
	int numQueries, numElements;
	//read elements
	cin >> numElements >> numQueries;
	arr.resize(numElements);
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
	int currR = 0, currL =0;
	
	for (query q : qs){
		int l = q.left, r = q.right;
		//remove elements previos range left
		while(currL< l){
			remove(currL);
			currL++;
		}
		//Add elements in the current range
		while(currL>l){
			add(currL-1);
			currL--;
		}
		while(currR<=r){
			add(currR);
			currR++;
		}
		//Remove elemnts previos range right
		while(currR > r+1){
			remove(currR-1);
			currR--;
		}
		printf("Sum  from [%d, %d]= %d \n", q.left+1, q.right+1, numDiff);
	}
	
	return 0;
}
