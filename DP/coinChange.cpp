#include <bits/stdc++.h>
#define MAXCOINS (10005)
#define MAXVALUE (105)

using namespace std;
typedef vector < int > vi;

int dp[MAXVALUE][MAXCOINS];
vi coins;

int ways(int target, int numCoins){
	if ( 0 == target) return 1;
	if ( 0 > target) return 0;
	if ( numCoins <= 0 && target >0) return 0;
	        /////////// A                    //////////// B
	return ways(target, numCoins-1) + ways(target - coins[numCoins -1], numCoins);
}

int waysdp(int target, int numCoins){
	for( int i=0; i< coins.size(); i++) dp[i][0] = 1;
	for(int i = 1 ; i<= target; i++){
		for (int c = 0; c < coins.size(); c++){
			//B
			int x =0 , y = 0;
			if(i-coins[c] >= 0) x = dp[i - coins[c]][c];
			//A
			if( c >=1) y = dp[i][c-1];
      // total count
      dp[i][c] = x + y;
		}
	}
}

int main(){
	coins.insert(coins.end(), {1,3,9});
	cout <<  ways(9, coins.size());
	return 0;
}
