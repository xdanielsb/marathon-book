#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
bool sieve[MAXN + 5];
vector <int> pri; //pri

void build_sieve(){
    memset(sieve, false, sizeof(sieve));
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= MAXN; i ++){
        if (!sieve[i]){
            for (int j = i * i; j <= MAXN; j += i){
                sieve[j] = true;
            }
        }
    }
    for (int i = 2; i <= MAXN; ++i){
        if (!sieve[i]) pri.push_back(i);
    }
}

vector <long long> fact(long long a){
    // Se asume que se tiene y 
    // se llamó la función build_sieve()
    vector <long long> ans;
    long long b = a;
    for (int i = 0; 1LL * pri[i] * pri[i] <= a; ++i){
        int p = pri[i];
        while (b % p == 0){
            ans.push_back(p);
            b /= p;
        }
    }
    if (b != 1) ans.push_back(b);
    return ans;
}

int main(){
    build_sieve();
    long long num_to_fact;
    cin >> num_to_fact;
    vector < long long > vll = fact(num_to_fact);

    for (int x=0; x< vll.size(); x++){
        cout << vll[x] << " "; 
    }
    cout << endl;
}
