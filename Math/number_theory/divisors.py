def listDivisors(n):
    divisors = []
    lim = int(math.sqrt(n))

    for i in range(1, lim + 1):
        if n % i == 0:
            divisors.append(i)

            if i != lim:
                divisors.append(n // i)

    return divisors
