import math

def listDivisors(n):
    divisors = []
    lim = int(math.sqrt(n))

    for i in range(1, lim + 1):
        if n % i == 0:
            divisors.append(i)

            if (i * i) != n:
                divisors.append(n // i)

    return divisors

def main():
    d = listDivisors(851)
    print(len(d))
    print(d)
main()
