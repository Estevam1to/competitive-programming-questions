import math

def to2(x):
    return x * x

n, k = map(int, input().split())

aux = int(math.sqrt(k))

print(to2(n + (n - aux + 1)))
