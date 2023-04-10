def printAnswer(m, n, numbers, operations, times):
    prefix_sum = [0] * (n + 1)
    total_times = 0
    
    for i in range(m):
        start, end, value = operations[i]
        total_times += times[i]
        prefix_sum[start] += total_times * value
        prefix_sum[end + 1] -= total_times * value
        
    sum = 0
    for i in range(n):
        sum += prefix_sum[i]
        numbers[i] += sum
        
    print(*numbers)

def main():
    n, m, k = map(int, input().split())
    numbers = list(map(int, input().split()))
    operations = []
    times = [0] * (m + 1)
    
    for i in range(m):
        l, r, d = map(int, input().split())
        operations.append((l - 1, r - 1, d))
    
    for i in range(k):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        times[x] += 1
        times[y + 1] -= 1
        
    printAnswer(m, n, numbers, operations, times)
        
main()
