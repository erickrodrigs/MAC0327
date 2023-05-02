def getNumberOfBeautifulPermutations(n):
    if n % 2 != 0:
        return 0
    
    mod = 998244353
    permutations = 1
    for j in range(1, n // 2 + 1):
        permutations *= j
        permutations %= mod
    
    return (permutations * permutations) % mod

def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        print(getNumberOfBeautifulPermutations(n))

main()
