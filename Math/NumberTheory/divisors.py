import math
"""Get the divisors of a number"""
def listDivisors(n):
    divisors = set()
    lim = int(math.sqrt(n))

    for i in range(1, lim + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)

    return divisors

def main():
    d = listDivisors(100)
    print(len(d))
    print(d)

main()
