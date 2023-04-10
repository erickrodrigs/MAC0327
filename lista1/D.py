def can_smallest_grow_to_height(n, m, w, middle, heights):
    accumulated = 0
    days = 0
    decreasing = [0] * n

    for i in range(n):
        accumulated -= decreasing[i]

        if heights[i] > middle:
            continue

        difference = middle - heights[i] - accumulated

        if difference > 0:
            if m - days < difference:
                return False
            
            days += difference
            accumulated += difference

            if i + w < n:
                decreasing[i + w] = difference
            
    return True    

def main():
    n, m, w = map(int, input().split())
    heights = list(map(int, input().split()))
    min_height = min(heights)
    max_height = max(map(lambda x: x + m, heights))
    answer = 0

    while min_height <= max_height:
        middle = (min_height + max_height) // 2

        if can_smallest_grow_to_height(n, m, w, middle, heights):
            answer = middle
            min_height = middle + 1
        else:
            max_height = middle - 1

    print(answer)

main()
