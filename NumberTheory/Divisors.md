
### Get all the divisors of a number.
* Time Complexity : O(sqrt(n))
* [Source](http://www.geeksforgeeks.org/find-divisors-natural-number-set-1/ "Find Divisors")


    def listDivisors(n):
        divisors = []
        lim = int(math.sqrt(n))

        for i in range(1, lim + 1):
            if n % i == 0:
            divisors.append(i)

            if i != lim:
                divisors.append(n // i)

        return divisors
