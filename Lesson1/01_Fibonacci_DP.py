# Fibonacci using Recursion
# by Yiyang 17_01_18

fiboValues = {1:1, 2:1}

def _Fibonacci(N):
    
    if N in fiboValues:
        return fiboValues[N]
    else:
        fiboValues[N] = _Fibonacci(N-1) + _Fibonacci(N-2)
        return fiboValues[N]

N = int(input("Enter an integer: "))
for i in range(1, N+1+1):
    print(i, _Fibonacci(i))
    
    