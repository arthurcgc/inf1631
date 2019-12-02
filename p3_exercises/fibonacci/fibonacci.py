

def fib(n):
    fib = [1 for _ in range(n)]
    for i in range(2, n):
        fib[i] = fib[i-1] + fib[i-2]
    return fib

if __name__ == "__main__":
    n = 10
    print(fib(10))