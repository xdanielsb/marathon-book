def merge_sort(array):
    ##Stop when the len of the array is less or equal than one
    if len(array)>1:  
        #Calc the mid of the array
        mid = len(array) // 2 # // mean integer division

        #Create two arrays left and right
        lefthalf = array[:mid] 
        print(lefthalf)

        righthalf = array[mid:]
        print(righthalf)

        #Divide the subarrays left and right
        merge_sort(lefthalf)
        merge_sort(righthalf)
        
        ##I send the array as a argument to change the same array and not another
        merge(lefthalf, righthalf, array)


def merge(lefthalf, righthalf, array):
    index_array_left=0
    index_array_right=0
    k=0
    while index_array_left < len(lefthalf) and \
          index_array_right < len(righthalf):

        if lefthalf[index_array_left] < \
            righthalf[index_array_right]:
            
            #assign the less to the new array 
            array[k]=lefthalf[index_array_left]

            """As the less was an element in the lefthalf we dont 
            need to compare this again so we increase the index
            of the left array"""
            index_array_left=index_array_left+1
        
        else:
            array[k]=righthalf[index_array_right]

            """As the less was an element in the righthalf we dont 
            need to compare this again so we increase the index
            of the left array"""
            index_array_right=index_array_right+1

        #It is necesary increase the pos of the original array
        k=k+1

    ##add the remaining elements
    while index_array_left < len(lefthalf):
        array[k]=lefthalf[index_array_left]
        index_array_left=index_array_left+1
        k=k+1

    while index_array_right < len(righthalf):
        array[k]=righthalf[index_array_right]
        index_array_right=index_array_right+1
        k=k+1



array = [-10, 37, 98 , 0 ,12, 192, 5]
print("Original Array")
print(array)
merge_sort(array)

print("Sorted Array")
print(array)

