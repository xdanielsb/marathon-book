"""
    Apply different function over an array
"""

def square(num):
    return num ** 2

def cube(num):
    return num ** 3

def is_pair(num):
    return num % 2

functions = [square, cube, is_pair]

array = range(0,20)

for elemn in array:
    value = map(lambda x: x(elemn), functions)  
    print (elemn, value)
