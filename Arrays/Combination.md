###  Give the combiantions of a given string.
* n is the number of elements

| Case          | Time Complexity |
| ------------- |:---------------:|
| Always        | O(C(n,r))          |


```python   
def combination(array, data, start, end, index, r):
    if (index == r): 
        print (data)
        return
    for i in range(start, end+1):
        """ "end-i+1 >= r-index" makes sure that including one element
             at index will make a combination with remaining elements
             at remaining positions
        """
        if (end - i + 1 >= r - index):
            data[index] = array[i]
            combination(array, data, i+1, end, index + 1, r)

def get_combinations(array, r, n):
    combination(array, [0] * r, 0, n-1,  0, r)


if __name__ == "__main__":
    array = [0,1,2,3,4,5]
    r = 5
    n  = len(array) 
    get_combinations(array, r, n)


```
