//Some useful equations
int main(){
  //area portion of a circle
  A = pi*r^2 * (theta/(2*pi))
  //area chord of a circle
  A = R * R * acos((R - h)/R) - (R - h) * sqrt(2 * R * h - h * h)
    // h is the height of the chord h = R - hypot(x,y)
  // rotation matrix counnterclockwise
  [x' y'] = [[cost -sint] [sint cost]][x y]
  // rotation matrix clockwise
  [x' y'] = [[cost sint] [-sint cost]][x y]
}
