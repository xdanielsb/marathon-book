import math

def listDivisors(n):
    divisors = []
    lim = math.ceil(math.sqrt(n))

    for i in range(1, lim):
        if n % i == 0:
            divisors.append(i)

            if i != lim:
                divisors.append(n // i)

    return divisors
