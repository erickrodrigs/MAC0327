def maximum_sum_in_subarray(numbers, k):
    start = max(numbers)
    end = sum(numbers)

    while start < end:
        sum_subarray = 0
        count_subarrays = 1
        middle = (start + end) // 2
        
        for number in numbers:
            if sum_subarray + number > middle:
                count_subarrays += 1
                sum_subarray = number
            else:
                sum_subarray += number
        
        if count_subarrays <= k:
            end = middle
        else:
            start = middle + 1

    return start

def main():
    _, k = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(maximum_sum_in_subarray(numbers, k))

main()
