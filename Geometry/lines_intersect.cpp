#include <iostream>
#include <algorithm>
#include <limits>


using namespace std;

typedef long double ld;
typedef pair < ld, ld> point;
const ld INF = 9000000000000000000;

typedef struct line{
    // vy(y) + vx (x) = c; vy = 1
    ld vy;//value y
    ld vx;//value x
    ld c;// value coeficient
    point origin; //In the case of a segment
    bool segment;
    point destiny; //In the case of a segment
} line;

inline ld det(line l1, line l2){
    ld dete = (l1.vx * l2.vy ) - (l1.vy * l2.vx);
    return dete;
}

inline point intersect( line l1, line l2){
    //if det == 0 lines are parallel
    ld dete = det(l1,l2);
    if (dete != 0){
        //Apply crammer for compute the intersection
        ld x  = ((l1.c * l2.vy) - (l2.c * l1.vy )) / dete;
        ld y =  ((l1.vx * l2.c) - (l2.vx * l1.c)) / dete;
        return make_pair(x,y);   
    }
    return make_pair(INF, INF);
    
}

/*
 *Return the negative slope
 */

inline ld slope(line l1){

    ld m = (l1.destiny.second - l1.origin.second ) / ( l1.destiny.first - l1.origin.first);
    return -1* m;
}

/*
 * Compute the independent coeffiecient
 */
inline ld coeficient(line l1){
    //y -mx = b
    ld c = l1.origin.second + l1.vx*l1.origin.first;
    return c;
}



/*
 * Message 
 */

inline bool mintersect(point inter, line l1, line l2){
  ld x= inter.first; 
    ld y= inter.second;

    if( x != INF ){
        if(l1.segment && l2.segment){
            if( x >= min(l1.origin.first, l1.destiny.first) && 
                x >= min(l2.origin.first, l2.destiny.first) &&  
                x <= max(l2.origin.first, l2.destiny.first) &&  
                x <= max(l1.origin.first, l1.destiny.first) &&  
                y >= min(l1.origin.second, l1.destiny.second) && 
                y >= min(l2.origin.second, l2.destiny.second) &&  
                y <= max(l2.origin.second, l2.destiny.second) &&  
                y <= max(l1.origin.second, l1.destiny.second)  ){
                
                cout << "x= " << x<< " y= " <<y <<endl;
                return true;
            }else{
                cout << "The lines  does not collide";
                return false;
            }
        }else{
            cout << "x= " << x<< " y= " <<y <<endl;
            return true;
        }
    }else{
        cout<<"Lines are parallel \n";
        return false;
    }

}


int main(){
    line l1, l2;
    l1 = l2 = {}; //its valid only with -std=c++11


    l1.origin = make_pair(0,0);
    l1.destiny = make_pair(-2,2);
    l1.vx  = slope(l1);
    l1.vy = 1;
    l1.segment =true;
    l1.c = coeficient(l1);

    l2.origin = make_pair(0,0);
    l2.destiny = make_pair(-3,2);
    l2.vx  = slope(l2);
    l2.vy = 1;
    l2.segment = true;
    l2.c = coeficient(l2);

    
    point inter = intersect(l1, l2);
   
    mintersect(inter, l1, l2);
    

}

