'''
a trailing zero appears when you multiply a multiple of 5 by a multiple of 2
'''

def factorize(n, factor):
    total_factor_sum = 0
    while n > 1:
        n //= factor
        total_factor_sum += n

    return total_factor_sum

def main():
    t = int(input())

    while t > 0:
        n = int(input())
        by_2 = factorize(n, 2)
        by_5 = factorize(n, 5)
        print(by_2 if by_2 < by_5 else by_5)

        t -= 1

main()
