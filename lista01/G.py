import sys

def guess(start, end, piles):
    if start > end:
        print("! " + str(start + 1))
        sys.stdout.flush()
        return
    
    mid = (start + end) // 2
    k = mid - start
    sequence = ""
    for i in range(start + 1, mid + 2):
        sequence += " " + str(i)
    
    print("? " + str(k + 1) + sequence)
    sys.stdout.flush()
    
    expected_sum = sum(piles[start:mid+1])
    actual_sum = int(input())
    
    if actual_sum == expected_sum:
        guess(mid + 1, end, piles)
    else:
        guess(start, mid - 1, piles)

def main():
    t = int(input())
    
    while t > 0:
        n = int(input())
        piles = list(map(int, input().split()))
        guess(0, n - 1, piles)
        t -= 1

main()
