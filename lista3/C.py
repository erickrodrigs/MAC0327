def crivo():
    N = 1001
    is_prime = [True] * N
    is_prime[0] = is_prime[1] = False

    for p in range(2, N):
        if is_prime[p]:
            i = p * p

            while i < N:
                is_prime[i] = False
                i += p

    return is_prime

def main():
    n = int(input())
    is_prime = crivo()
    results = []

    for i in range(2, n + 1):
        if not is_prime[i]:
            continue

        num = 1
        while True:
            num *= i
            results.append(num)

            if num > n // i:
                break

    print(len(results))
    print(*results)

main()
