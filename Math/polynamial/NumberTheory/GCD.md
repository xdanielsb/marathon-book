### Calc greatest common divisor between two numbers

|               | Case             | Time Complexity |
| ------------- |:----------------:|:---------------:|
| Worst Case    | T(a,b)    b > a  | O(log(b))       |
| Best Case     | T(a,b)    a = b  | O(1)            |

```c++

int gcd(int x, int y){
    int g;

    if (x<0) x = -x;
    if (y<0) y = -y;
    if (x+y ==0 ) cerr << "Error" <<endl;

    g=y;
    
    while(x>0){
        g = x;
        x = y % x;
        y = g;
    }

    return g;
}

```

