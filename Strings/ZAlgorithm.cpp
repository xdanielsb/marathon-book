#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1000001
#define pb push_back
using namespace std;
typedef long long lld;
int Z[MAX]; //zarray
vector<int> matches;

//Complexity: O(N + M)

inline void zAlgorithm(string s, int m){
  int len = s.length();
  int L = 0, R = 0;
  for (int i = 1 ;i < len; i++){
    if (i > R) {
      L = R = i;
      while (R < len && s[R-L] == s[R]) R++;
      Z[i] = R-L;
      R--;
    }else {
      int k = i - L;
      if (Z[k] < R-i+1) Z[i] = Z[k];
      else {
        L = i;
        while (R < len && s[R-L] == s[R]) R++;
        Z[i] = R - L;
        R--;
      }
    }
    if (Z[i] == m) matches.pb(i - m - 1);
  }
}

int main() {
    string haystack = "abcabc", needle = "abc";
    int n = haystack.size(), m = needle.size();
    zAlgorithm(needle + "#" + haystack, m);
    cout << ("Locations where start to match. \n");
    for (int i=0;i<matches.size();i++) cout << matches[i] << " ";
    cout << endl <<"Number of matches: " << matches.size() << endl;

    return 0;
}
