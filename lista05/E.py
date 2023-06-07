MOD = 1000000007

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()

    comb = [[0 for _ in range(k)] for __ in range(n)]

    for i in range(n):
        for j in range(k):
            if j == 0 or j == i:
                comb[i][j] = 1
            else:
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD

    keysSum = 0
    for i in range(n):
        keysSum += (comb[i][k - 1] * arr[i])
        keysSum %= MOD

    print(keysSum)

main()
