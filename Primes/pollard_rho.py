import random 

def gcd( a, b):
    if(b == 0): return a;
    return gcd(b, a % b);

def pollardRho(N):
        if N%2==0:
                return 2
        x = random.randint(1, N-1)
        y = x
        c = random.randint(1, N-1)
        g = 1
        while g==1:             
                x = ((x*x)%N+c)%N
                y = ((y*y)%N+c)%N
                y = ((y*y)%N+c)%N
                g = gcd(abs(x-y),N)
        return g

print(pollardRho(10967535067))
