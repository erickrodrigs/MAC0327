import sys

def buildMemo(maxValue, n, weightsAndValues):
    dp = [sys.maxsize] * (maxValue + 1)
    dp[0] = 0

    for i in range(n):
        weight, value = weightsAndValues[i]
        for j in range(maxValue - value, -1, -1):
            dp[j + value] = min(dp[j + value], dp[j] + weight)
    
    return dp

def solveKnapsack2(n, w, weightsAndValues):
    maxValue = sum(map(lambda x: x[1], weightsAndValues))
    dp = buildMemo(maxValue, n, weightsAndValues)
    result = -sys.maxsize

    for i in range(maxValue + 1):
        if w >= dp[i]:
            result = max(result, i)

    return result

def main():
    n, w = map(int, input().split())
    weightsAndValues = []

    for _ in range(n):
        weight, value = map(int, input().split())
        weightsAndValues.append((weight, value))

    print(solveKnapsack2(n, w, weightsAndValues))

main()
