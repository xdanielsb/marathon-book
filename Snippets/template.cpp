//Constants and defines
#define show(x) cout << #x << " = " << x << endl;
#define endl '\n'
#define f first
#define s second
#define mp make_pair
#define pb push_back
const double PI = acos(-1);
const ld INF = 1e18;

// INT_MAX  -> limits.h

//Geometry
inline ld cross(point o, point d){ return(o.x * d.y)  - ( o.y * d.x); }
inline ld dot(point o, point d){ return (o.x * d.x)  + ( o.y * d.y); }
inline point diff(point o, point d){ return {d.x-o.x, d.y - o.y} ;}
inline ld dist(point o, point d){ return  sqrt(dot(r(o,d) , r(o,d))); }

//Main
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
