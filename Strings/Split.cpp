#include <bits/stdc++.h>

using namespace std;
/*
 * Split by space
 */
int main(){
    string line;
    while(getline(cin, line)){
        stringstream ss;
        ss.str(line);
        string item;
        while (getline(ss, item,' ')) {
            cout << item << endl;
        }
    }
    return 0;
}
