MOD = 1000000007

def count_triples(n1, n2, n3):
    first, second, third = map(lambda x: x % MOD, sorted([n1, n2, n3]))
    return (((first % MOD) * (second - 1 + MOD)) % MOD * (third - 2 + MOD)) % MOD

def main():
    t = int(input())
    for _ in range(t):
        n1, n2, n3 = map(int, input().split())
        print(count_triples(n1, n2, n3))

main()
