### Change a  number from a base ob to a base od.
* n is the number of elements

| Case          | Time Complexity |
| ------------- |:---------------:|
| Always        | O(n!)          |


```python   
def permutation(array, start = 0):
    if (start == len(array)):
        print(array)
        return
    for i in range(start, len(array)):
        array[start], array[i] = array[i], array[start]
        permutation(array, start + 1)
        array[start], array[i] = array[i], array[start]

permutation(['d','a','n'])
```

