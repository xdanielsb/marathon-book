#include <bits/stdc++.h>
#define pb push_back
#define ROWS 10
#define endl '\n'
#define COLS 10
#define mp make_pair
using namespace std;
struct point {
  int x, y;
  point() {}
  point(int _x, int _y){
    x = _x;
    y = _y;
  }
  point operator + (point p) const { return point(p.x + x, p.y +y);  }
  point operator - (point p) const { return point(x - p.x, y -p.y);  }
  bool operator == (point p) const { return x==p.x && y ==p.y; }
  bool operator <(point p) const { return p.x < x || p.y<y; } // set vis
  void show(){ printf("x= %d, y=%d\n", x, y);}
};

vector < point > dir = {point(1,0), point(-1,0), point(0,1), point(0,-1)};;
int r , c, salx, saly;

char mat[ROWS][COLS];
set < pair < int , int > > vis;
point sal;

bool inBoundaries(point &p){
  if(p.x >= 0 && p.y >=0 && p.x < r &&  p.y<c) return true;
  return false;
}

bool sol(point in){
  if (in == sal) return true;
  queue < point > q;
  q.push(in);
  while (!q.empty()){
    point actual = q.front();
    vis.insert(mp(in.x, in.y));
    q.pop();
    actual.show();
    for (int i= 0; i < 4; ++i){
      point p = actual + dir[i];
      if( inBoundaries(p) && (vis.count(mp(p.x, p.y))==0)){
        q.push(p);
        vis.insert(mp(p.x, p.y));
        cout  << '\t';
        p.show(); 
        if (p == sal) return true;
      }
    }
  }
  return false;
}


int main(){
	#ifdef LOCAL
		freopen("in.c", "r", stdin);
	#endif
  vis.clear();
  //rows and cols
  cin >> r  >> c;
  for ( int row =0 ; row < r ; row++){
    for (int col = 0; col < c; col++){
      cin >> mat[row][col];
    }
  }
  sal.x = sal.y =2;
  point ini(1,1);
  sol(ini);
  return 0;
}
