#include<bits/stdc++.h>
#define debug(x) cout << #x << " = "<< x << endl
#define pb push_back
/*
	Algorithm to find all possible substrings of size k given a set of values
*/
using namespace std;
set<string> subs;

//print all possible substrings of size k
void substringSizek(char set[], string prefix, int n, int k){
	//Base case
	if( 0 == k){
		cout << prefix <<endl;
		subs.insert(prefix);
		return;
	}
	for( int i=0;  i < n ; ++i){
		string newprefix = prefix + set[i];
		//k is decreased because we add a new caracter
		substringSizek(set, newprefix, n, k-1);
	}
}
void init(char set[], int k){
	 int n = strlen(set);
	 substringSizek(set, "", n, k);
}

int main(){
	char set[3] ={'a', 'b'};
	int k = 3;
	init(set, k);
	/*
	aaa
	aab
	aba
	abb
	baa
	bab
	bba
	bbb
	*/
}
