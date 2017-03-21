package main

import "fmt"

func main() {
	fmt.Println("Insertion sort Go")
	length_array := 8
	array := make ([]int, 0, length_array)
	array = append(array, 50, 885, 1 , -8 , 54 , 2, 54, 0)
	fmt.Println("Original array")
	show (array, length_array)

	fmt.Println("Sorted Array")
	sorted_array := sort (array, length_array)
	show (sorted_array, length_array)
}

func show (array  []int , length_array int){
	for index := 0; index < length_array; index++{
		element := array [index]
		fmt.Printf("%d ",element)
	}
	fmt.Println("")
}

func sort(array []int, length_array int)([]int){
	for index := 1; index < length_array ; index++{  // the position "1" is the second position
		key := array[index]
		index_aux := index -1
		for index_aux >= 0 &&  array[index_aux] > key {
			array[index_aux +1] = array[index_aux]
			index_aux = index_aux -1
		}
		array[index_aux+1]= key
	}
	return array
}
