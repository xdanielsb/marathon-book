#include <bits/stdc++.h>
using namespace std;

/*
	Graham Scan O(nlogn)
*/
struct point {
  int x, y;
  point() {}
  point(int _x, int _y){
    x = _x;
    y = _y;
  }
};
point p0;
point nextToTop(stack<point> &S){
  point p = S.top();
  S.pop();
  point res = S.top();
  S.push(p);
  return res;
}
int swap(point &p1, point &p2){
  point temp = p1;
  p1 = p2;
  p2 = temp;
}
int distSq(point p1, point p2){
  return (p1.x - p2.x)*(p1.x - p2.x) +
         (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(point p, point q, point r){
  int val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;  // colinear
  return (val > 0)? 1: 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2){
 point *p1 = (point *)vp1;
 point *p2 = (point *)vp2;
 int o = orientation(p0, *p1, *p2);
 if (o == 0)
   return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 return (o == 2)? -1: 1;
}
stack<point> convexHull(point points[], int n){
 int ymin = points[0].y, min = 0;
 for (int i = 1; i < n; i++){
   int y = points[i].y;
   if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
      ymin = points[i].y, min = i;
 }
 swap(points[0], points[min]);
 p0 = points[0];
 qsort(&points[1], n-1, sizeof(point), compare);
 int m = 1;
 for (int i=1; i<n; i++){
   while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0){
      i++;
    }
   points[m] = points[i];
   m++;
 }
 
 stack<point> S;
 if (m < 3) return S ;
 S.push(points[0]);
 S.push(points[1]);
 S.push(points[2]);

 for (int i = 3; i < m; i++){
    while (orientation(nextToTop(S), S.top(), points[i]) != 2)
       S.pop();
    S.push(points[i]);
 }
  return S;
}
int main(){
    point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    stack <point > s = convexHull(points, n);
    while (!s.empty()){
     point p = s.top();
     cout << "(" << p.x << ", " << p.y <<")" << endl;
     s.pop();
   	}
    return 0;
}
