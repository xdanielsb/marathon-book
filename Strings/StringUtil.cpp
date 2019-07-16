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
string toString(double d){
  stringstream ss;
  ss << fixed << setprecision(10) << d;
  string num = ss.str();
  return num;
}
void tolowers(string &data){
 transform(data.begin(), data.end(), data.begin(), ::tolower);
}
void replace(string &a,  string &from, string &to){
	int pos=0;
	while((pos = a.find(from,pos)) != string::npos){
		a.replace(pos, to.size(), to);	
		pos+=to.size();
	}
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
  string hay ="hellohowareyouhow",  ned ="whatare", from= "how";
  replace(hay, from, ned);
  cout << hay <<endl;
  return 0;
}
