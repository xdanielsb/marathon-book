"""
    Apply different function over an array
"""
def square(num): return num ** 2
def cube(num): return num ** 3
def is_pair(num): return num % 2
functions = [square, cube, is_pair]
array = [1, 7, -2, 4 , 5,10, 0]
for elemn in array:
    value = map(lambda x: x(elemn), functions)
    print (elemn , end=" :")
    [print (x, end=" ") for x in value if x != None]
    print()
