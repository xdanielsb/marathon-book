#include<bits/stdc++.h>
#define pb push_back
#define debug(x) cout << #x << " = "<< x << endl;
using namespace std;
const int MAX_POINTS = 20;

struct point {
  int x, y;
  point() {}
  point(int _x, int _y){
    x = _x;
    y = _y;
  }
};

typedef vector < point > vp;
vp poly, clipper;
/*
	Algorithm intersection of polygons;
*/
// Returns x-value of point of intersectipn of two lines
int x_intersect(int x1, int y1, int x2, int y2,   //l1
                int x3, int y3, int x4, int y4){  //l2
	int num = (x1*y2 - y1*x2) * (x3-x4) -
		      	(x1-x2) * (x3*y4 - y3*x4);
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}

// Returns y-value of point of intersectipn of two lines
int y_intersect(int x1, int y1, int x2, int y2,  //l1
                int x3, int y3, int x4, int y4){ //l2
	int num = (x1*y2 - y1*x2) * (y3-y4) -
		      	(y1-y2) * (x3*y4 - y3*x4);
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}

// This functions clips all the edges w.r.t one clip edge of clipping area
void clip(int &psize, int csize, int x1, int y1, int x2, int y2) {        	
	int  npsize = 0; // new points
	vp npoints(MAX_POINTS);
	for (int i = 0; i < psize; i++){
		// i and k form a line in polygon
		int k = (i+1) % psize;
		int ix = poly[i].x, iy = poly[i].y;
		int kx = poly[k].x, ky = poly[k].y;

		// Calculating position of first point
		int i_pos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1);
		// Calculating position of second point
		int k_pos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1);

		// Case 1 : When both points are inside
		if (i_pos < 0 && k_pos < 0){
			//Only second point is added
			npoints[npsize].x = kx;
			npoints[npsize].y = ky;
			npsize++;
		}

		// Case 2: When only first point is outside
		else if (i_pos >= 0 && k_pos < 0){
			npoints[npsize].x = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			npoints[npsize].y = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			npsize++;

			npoints[npsize].x = kx;
			npoints[npsize].y = ky;
			npsize++;
		}
		// Case 3: When only second point is outside
		else if (i_pos < 0 && k_pos >= 0){
			//Only point of intersection with edge is added
			npoints[npsize].x = x_intersect(x1,y1, x2, y2, ix, iy, kx, ky);
			npoints[npsize].y = y_intersect(x1,y1, x2, y2, ix, iy, kx, ky);
			npsize++;
		}
	}

	psize = npsize;
	
	for (int i = 0; i < psize; i++){
		poly[i].x = npoints[i].x;
		poly[i].y = npoints[i].y;
	}
}

// Implements Sutherland–Hodgman algorithm
void suthHodgClip(int psize,  int csize){
	for (int i=0; i<csize; i++){
		//i and k are two consecutive indexes
		int k = (i+1) % csize;
		clip(psize, csize, clipper[i].x,	clipper[i].y, clipper[k].x,	clipper[k].y);
	}
}

int main(){
	// Defining polygon vertices in clockwise order
	
	poly.pb(point(0,0));
	poly.pb(point(0,100));
	poly.pb(point(100,100));
	poly.pb(point(100,0));
	
	int psize = poly.size();
	
	// clipper vertices in clockwise order
	clipper.pb(point(50, 50));
	clipper.pb(point(200, 50));
	clipper.pb(point(200, 0));
	int csize = clipper.size();
	
	//init
	suthHodgClip(psize, csize);
	
	//print solution
	for (int i=0; i < psize; i++)
		cout << '(' << poly[i].x <<", " << poly[i].y << ") ";

	return 0;
}

