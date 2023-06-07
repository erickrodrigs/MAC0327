def crivo():
    N = 10**6 + 1
    is_prime = [True] * N
    is_prime[0] = is_prime[1] = False

    for p in range(2, N):
        if is_prime[p]:
            i = p * p

            while i < N:
                is_prime[i] = False
                i += p

    return is_prime

def is_t_prime(number, is_prime):
    square_root = number ** 0.5
    return square_root == int(square_root) and is_prime[int(square_root)]

def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    is_prime = crivo()

    for number in numbers:
        if number == 4:
            print("YES")
            continue
        if number < 4 or number % 2 == 0:
            print("NO")
            continue

        print("YES" if is_t_prime(number, is_prime) else "NO")

main()
