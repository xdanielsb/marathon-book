def show(elements):
    for element in elements:
        print(element, end =" ")
    print("")

def sort(elements, array_length):
    for i in range(0, array_length):
        smallest = elements[i]
        pos_smallest = i
        for index in range(i+1,array_length):
            if elements[index] < elements[pos_smallest]:
                pos_smallest = index
        aux = elements[i]
        elements[i] = elements[pos_smallest] 
        elements[pos_smallest] =aux 

if __name__ == "__main__":
    elements = [23, -3, 85, 0, 21, -10, 40] 
    array_length =  len(elements)
    print("original array")
    show(elements)
    print("sorted array")
    sort(elements, array_length)
    show(elements)
