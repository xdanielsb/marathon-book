#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1000001
#define pb push_back
using namespace std;
typedef long long lld;
int z[MAX]; //zarray
vector<int> matches;

//Complexity: O(N + M)

inline void zAlgorithm(string s, int m){
  int len = s.length();
  int l = 0, r = 0;
  for (int i = 1 ;i < len; i++){
    if (i > r) {
      l = r = i;
      while (r < len && s[r-l] == s[r]) r++;
      z[i] = r-l;
      r--;
    }else {
      int k = i - l;
      if (z[k] < r-i+1) z[i] = z[k];
      else {
        l = i;
        while (r < len && s[r-l] == s[r]) r++;
        z[i] = r - l;
        r--;
      }
    }
    if (z[i] == m) matches.pb(i - m - 1);
  }
}

int main() {
  string haystack = "abcabc", needle = "abc";
  int n = haystack.size(), m = needle.size();
  zAlgorithm(needle + "#" + haystack, m);
  cout << ("locations where start to match. \n");
  for (int i=0;i<matches.size();i++) cout << matches[i] << " ";
  cout << endl <<"Number of matches: " << matches.size() << endl;
  return 0;
}
