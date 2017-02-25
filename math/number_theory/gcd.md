### Calc greatest common divisor between two numbers

|               | Case             | Time Complexity |
| ------------- |:----------------:|:---------------:|
| Worst Case    | T(a,b)    b > a  | O(log(b))       |
| Best Case     | T(a,b)    a = b  | O(1)            |

```c
/* CALC GREATEST COMMON DIVISOR BY EUCLIDES ALGORITHM
 * r -> remainder
 * q -> quotient
 */   
int calc_gcd(int n1, int n2, int r, int q){
    if (r == 0)
        return n2;
    return calc_gcd(n2,r,n2 % r, n2 / r);
}

/* FIRE UP THE FUNCTION GCD
 */
int gcd(int n1, int n2){
    if ( n1 > n2 )
        return calc_gcd(n1, n2, n1 % n2, n1 / n2);
    return calc_gcd(n2, n1, n2 % n1, n2 / n1);
}
```
