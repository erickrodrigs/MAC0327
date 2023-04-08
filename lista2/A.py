
def getCumulativeSumArray(numbers):
    cumulativeSumArray = []
    cumulativeSum = 0
    
    for num in numbers:
        cumulativeSum += num
        cumulativeSumArray.append(cumulativeSum)
        
    return cumulativeSumArray

def answerQueries(numbers, cumulativeSumArray):
    num_queries = int(input())
    
    while num_queries > 0:
        start, end = map(int, input().split())
        result = cumulativeSumArray[end] - cumulativeSumArray[start] + numbers[start]
        print(result)
        num_queries -= 1
        
def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    cumulativeSumArray = getCumulativeSumArray(numbers)
    answerQueries(numbers, cumulativeSumArray)
    
main()
