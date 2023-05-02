# NOT WORKING!!!!

MOD = 1000000007

def C(a, b):
    factorial = [1] * (a + 1)

    for i in range(2, a + 1):
        factorial[i] = (factorial[i - 1] * i) % MOD
    
    return (factorial[a] * pow(factorial[b], MOD - 2, MOD) * pow(factorial[a - b], MOD - 2, MOD)) % MOD

def main():
    n = int(input())
    while n > 0:
        a, b = map(int, input().split())
        print(C(a, b))

        n -= 1

main()
