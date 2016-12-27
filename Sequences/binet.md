### COMPUTE THE NTH FIBONACCI NUMBER USING BINETS FORMULA 

####Definition of fibonacci
+![Alt Fibonacci](assets/fibo.png?raw=true "Fibonacci")


####Definition of Binet's formula
+![Alt Binets Formula](assets/binetsformula.png?raw=true "Binets Formula")


####n is the nth number in the fibonacci sequence


|               | Case             | Time Complexity |
| ------------- |:----------------:|:---------------:|
| Worst Case    | T(n)             |                 |
| Best Case     | T(n)             |                 |



```go
package main

import (
	"fmt"
	"math"
)

/*
* Compute the nth fibonacci number using the binet's formula
 */
func nth_fibo(n int) (nth float64) {
	fi := (1 + math.Sqrt(5)) / 2
	ga := (1 - math.Sqrt(5)) / 2
	nth = (math.Pow(fi, float64(n)) - math.Pow(ga, float64(n))) / (math.Sqrt(5))
	return
}

func main() {
	n := 100
	fmt.Println(" nth fibo =  ", nth_fibo(n))
}
```

