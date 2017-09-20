#include <bits/stdc++.h>
using namespace std;
int main(){
    string line;
    while (getline(cin, line)){
        stringstream ss(line);
        string word;
        int count = 0;
        while ( ss >> word) count ++;
        cout << endl << "# Words: " << count << endl;
    }
}
