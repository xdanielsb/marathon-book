#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector <string> vs;
int toNum(string a){
	stringstream toNum(a);
	int num;
	toNum >> num;
	return num;
}
vs split(string line, char d){
	vector < string > elements;
	stringstream ss(line);
	string item;
	while(getline(ss, item, d))	elements.pb(item);
	return elements;
}

int main(){
  vs d1 = split("1990/10/5", '/');
  for (string s: d1){
    cout << toNum(s) << endl;
  }

  char a = 'a';
  cout << (isalnum(a)?"true":"false")  << endl;
  cout <<( isalpha(a)?"true":"false") << endl;
  cout << (isblank(a)?"true":"false")  << endl;
  cout << (isdigit(a)?"true":"false")  << endl;
  cout << (islower(a)?"true":"false")  << endl;
  cout << (ispunct(a)?"true":"false")  << endl;
  cout << (isupper(a)?"true":"false")  << endl;
  cout << (isxdigit(a) ?"true":"false") << endl;
  cout << (char)tolower(a) << endl;
  cout << (char)toupper(a) << endl;
  return 0;
}
