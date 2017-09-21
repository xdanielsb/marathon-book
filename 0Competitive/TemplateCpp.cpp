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
// INT_MAX  -> limits.h
typedef long long ll;
typedef vector < int > vi;
typedef vector < vi > vii;

//Geometry
inline ld cross(point o, point d){ return(o.x * d.y)  - ( o.y * d.x); }
inline ld dot(point o, point d){ return (o.x * d.x)  + ( o.y * d.y); }
inline point diff(point o, point d){ return {d.x-o.x, d.y - o.y} ;}
inline ld dist(point o, point d){ return  sqrt(dot(r(o,d) , r(o,d))); }

//Input
scanf("%d",&value); //int
scanf("%ld",&value); //long y long int
scanf("%c",&value); //char
scanf("%f",&value); //float
scanf("%lf",&value); //double
scanf("%s",&value); //char*
scanf("%lld",&value); //long long int
scanf("%x",&value); //int hexadecimal
scanf("%o",&value); //int octal

//Main
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  #ifdef UDVORAK
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif
}
