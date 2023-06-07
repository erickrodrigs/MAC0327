def main():
    sum_of_difference = 0
    n = int(input())
    A = list(map(int, input().split()))

    A.sort()

    for i in range(n):
        sum_of_difference += (2 * i - n + 1) * A[i]
    
    print(sum_of_difference)

main()
