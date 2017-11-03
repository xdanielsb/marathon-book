def merge_sort(arr):
    if (len(arr)>1):
        mid = len(arr) // 2
        lefthalf, righthalf = arr[:mid] , arr[mid:]
        merge_sort(lefthalf)
        merge_sort(righthalf)

        merge(lefthalf, righthalf, arr)


def merge(lh, rh, arr):
    il = 0
    ir = 0
    k = 0
    while il < len(lh) and ir < len(rh):
        if (lh[il] < rh[ir]):
            arr[k] = lh[il]
            il = il+1
        else:
            arr[k] = rh[ir]
            ir = ir+1
        k = k+1

    while il < len (lh):
        arr[k]= lh[il]
        il = il +1
        k = k+1

    while ir < len(rh):
        arr[k] = rh[ir]
        ir = ir +1
        k = k+1

def main():
    array = [-10, 37, 98 , 0 ,12, 192, 5]
    print("Original Array")
    print(array)
    merge_sort(array)

    print("Sorted Array")
    print(array)
main()
