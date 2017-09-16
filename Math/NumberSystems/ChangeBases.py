# coding=utf-8
""" CHANGE THE BASE OF A NUMBER
    ob -> origin base
    od -> destiny base
"""

chars = "0123456789ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"

def changeBase(number, ob,od):
    if ob == 10:
        return tob(number, od)
    return tob(to10(number,ob),od)

""" FROM ANY BASE TO BASE 10
    b -> base of the number n
    pos -> location of a sub-number in n
"""
def to10(n, b, pos =0):
   if n == 0: return 0
   return (n % 10)* (b  ** pos) + to10(n / 10, b, pos+1)

"""FROM TEN BASE TO ANOTHER BASE"""
def tob(n, b):
    if n == 0: return ""
    return   tob(n // b, b) + chars[n % b]

def main():
    print ( tob(7,2))
    print ( tob(252,16))
    print ( tob(234,15))
    print ( to10(1000,2))
    print ( changeBase(111,2,10))
main()
