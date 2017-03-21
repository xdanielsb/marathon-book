package main

import "fmt"

func main() {
	length_array := 7
	array := make([]int, 0, length_array)
	array = append(array, 50, 1, -40, 25, 36, 48, 10)
	fmt.Println("Original array")
	show(array, length_array)
	sorted_array := sort(array, length_array)
	fmt.Println("Sorted array")
	show(sorted_array, length_array)
}

func show(array []int, length_array int) {
	for index := 0; index < length_array; index++ {
		fmt.Printf("%d ", array[index])
	}
	fmt.Println("")
}

func sort(array []int, length_array int) []int {
	for index := 0; index < length_array; index++ {
		pos_smallest := index
		for index_aux := index + 1; index_aux < length_array; index_aux++ {
			if array[pos_smallest] > array[index_aux] {
				pos_smallest = index_aux
			}
		}
		//Swap
		if pos_smallest != index {
			aux := array[index]
			array[index] = array[pos_smallest]
			array[pos_smallest] = aux
		}
	}
	return array

}
