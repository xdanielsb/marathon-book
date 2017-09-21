#include <bits/stdc++.h>
using namespace std;

// INT_MAX  -> limits.h
typedef long long ll;
typedef long double ld;
typedef vector < int > vi;
typedef vector < vi > vii;
struct point {int x, y;};

//Constants and defines
#define show(x) cout << #x << " = " << x << endl;
#define endl '\n'
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define isOdd(x) (x & 0x01)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define foreach (x,v) for (typeof(v).begin() x=(v).begin(); x!=(v).end(); ++x)
#define sz(a) ((int)(a).size())
#define swap(x,y) (x^=y, y^=x, x^=y)

const double PI = acos(-1);
const ld INF = 1e18;
const double EPS = 1e-15;

//Geometry
inline ld cross(point o, point d){ return(o.x * d.y)  - ( o.y * d.x); }
inline ld dot(point o, point d){ return (o.x * d.x)  + ( o.y * d.y); }
//inline point diff(point o, point d){ return {d.x-o.x, d.y - o.y} ;}
//inline ld dist(point o, point d){ return  sqrt(dot(diff(o,d) , diff(o,d))); }

void input(){
  /*
  scanf("%d",&value); //int
  scanf("%ld",&value); //long y long int
  scanf("%c",&value); //char
  scanf("%f",&value); //float
  scanf("%lf",&value); //double
  scanf("%s",&value); //char*
  scanf("%lld",&value); //long long int
  scanf("%x",&value); //int hexadecimal
  scanf("%o",&value); //int octal
  */
}

void tricks(){
  int a=21,b=16,c=8;
  //if the numbers are long and long long end with and l or two l
  /*ie
    int
    __builtin_popcount
    long
    __builtin_popcountl
    long long
    __builtin_popcountll
    */
  //log2 floor
  show(__lg(21));
  show(__lg(16));
  show(__lg(8));
  cout << endl;
  //count the number of ones
  show(__builtin_popcount(16));
  show(__builtin_popcount(15));
  show(__builtin_popcount(0));
  cout << endl;

  //count the trailing zeros zer
  show(__builtin_ctz(16));
  show(__builtin_ctz(5));
  cout << endl;

  //count the leading zeros
  show(__builtin_clz(32));
  show(__builtin_clz(1024));
  cout << endl;
  //Returns one plus the index of the least significant
  //1-bit of x, or if x is zero, returns zero.
  show(__builtin_ffs(5));
  cout << endl;
  //swap variables
  swap(a,b);
  show(a);
  show(b);
  cout <<endl;
  //Is a number ´x´ power of 2?
  show(((a & (a-1))==0));
  show(((b & (b-1))==0));
  cout << endl;

  //turn on the first n bits of a mask
  show(((1LL<<10)-1));
}

//Main
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  tricks();
  #ifdef UDVORAK
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif
}
