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
	nth = (math.Pow(fi, float64(n)) - 
           math.Pow(ga, float64(n))) / (math.Sqrt(5))
	return
}

func main() {
	n := 10
	fmt.Println(" nth fibo =  ", math.Ceil(nth_fibo(n)))
}
