#include <stdio.h>
using namespace std;
const double EPS = 1e-15;
/*
 * Return
 * -1  if x < y
 *  0  if x == y
 *  1  if x > y
 */
int cmp (double x, double y){
    return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}
int main(){
  double d1 = 0.00000000000212;
  double d2 = 0.00000000000213;
  int res = cmp(d1,d2);
  if (res == 0){
    printf("Equal \n");
  }else if(res == 1){
    printf("Greater\n");
  }else {
    printf("Less \n");
  }
}
