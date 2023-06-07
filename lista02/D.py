def findCost(n, numbers):
    answers = [0] * n
    index = n - 1
    factorial = 0
    
    while index >= 0:
        if numbers[index] < factorial + 1:
            break
        factorial += 1
        index -= 1
        
    for i in range(n - 1, -1, -1):
        answers[i] = factorial
        
        if index < 0 or numbers[index] < factorial:
            factorial -= 1
        else:
            index -= 1
            
    print(*answers)

def main():
    t = int(input())
    
    while t > 0:
        n = int(input())
        numbers = list(map(int, input().split()))
        findCost(n, numbers)
        t -= 1

main()
