import math, sys
MAXN = 431
choose = []
for i in range (0, MAXN+5):
    choose.append([0]*(MAXN+5))
def binomial(N):
    for n in range (0, N+1):
        choose[n][0] = choose[n][n] = 1
    for n in range(1, N+1):
        for k in range(1, n):
            choose[n][k] = choose[n-1][k-1] + choose[n-1][k]
if __name__ == "__main__":
    N = 431
    binomial(N)
    n, k = 10, 4
    print(choose[n][k])
