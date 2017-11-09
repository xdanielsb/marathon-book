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
	int id;
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
vi sols;


void add(int pos){
	cnt[arr[pos]]++;
	if(cnt[arr[pos]] == 1 ) numDiff++; // new element
}

void remove(int pos){
	cnt[arr[pos]]--;
	if(cnt[arr[pos]] == 0 ) numDiff--; //remove element
}


int main(){
	#ifdef LOCAL
		freopen("in.c", "r", stdin);
	#endif
	int numQueries, numElements;
	//read elements
	cin >> numElements;
	arr.resize(numElements);
	for( int i=0; i<numElements; i++){
		cin >> arr[i];
	}
	
	cin >> numQueries;
	//read queries
	vq qs(numQueries);
	sols.resize(numQueries);
	for( int q=0; q<numQueries; q++){
		cin >>  qs[q].left >> qs[q].right;
		qs[q].left--;
		qs[q].right--;
		qs[q].id = q; 
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
		sols[q.id] = numDiff;
	}
	for(int i=0; i<numQueries; ++i){
		cout << sols[i] <<endl;
	}
	return 0;
}
