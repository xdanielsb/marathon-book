
def show(array):
    for element in array:
        print(element, end = " ")
    print("")


def sort(array, length_array):
    for index in range(1,length_array):
        key = array[index]
        index_aux = index -1
        while index_aux >=0 and array[index_aux]>key:
            array[index_aux+1] = array[index_aux]
            index_aux = index_aux -1
        array[index_aux+1]=key


def main():
    array = [50, 885, 1 , -8 , 54 , 2, 54, 0]
    print("Original array")
    show(array)
    print("Sorted array")
    sort(array, len(array))
    print(array)
main()
