### Calc least common multiple

|               | Case             | Time Complexity |
| ------------- |:----------------:|:---------------:|
| Worst Case    | T(a,b)    b > a  | O(log(b))       |
| Best Case     | T(a,b)    a = b  | O(1)            |

```c
#include <stdio.h>
#include "GCD.c"

/*CALC THE LEAST COMMON DIVISOR
 */
int lcd(int n1, int n2){
    return (n1 * n2) / gcd(n1,n2);
}
```

