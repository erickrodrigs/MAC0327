def main():
    q = int(input())
    
    while q > 0:
        k, n, a, b = map(int, input().split())
        max_num_a = -1
        start = 0
        end = n
        
        while start <= end:
            num_a = (start + end) // 2
            num_b = n - num_a;
            total = num_a * a + num_b * b
            
            if total < k:
                max_num_a = max(max_num_a, num_a)
                start = num_a + 1
            else:
                end = num_a - 1
        
        print(max_num_a)
        q -= 1

main()
