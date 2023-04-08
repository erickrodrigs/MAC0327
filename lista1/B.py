def calculateMaxDistance(n, h, flows):
    maxDistance = flows[0][1] - flows[0][0]
    answer = maxDistance
    requiredHeight = 0
    last = 0

    for i in range(1, n):
        requiredHeight += flows[i][0] - flows[i - 1][1] 

        while requiredHeight >= h:
            requiredHeight -= flows[last + 1][0] - flows[last][1]
            maxDistance -= flows[last][1] - flows[last][0]
            last += 1

        maxDistance += flows[i][1] - flows[i][0]
        if maxDistance > answer:
            answer = maxDistance

    return answer + h

def main():
    n, h = map(int, input().split())
    flows = []

    for _ in range(n):
        x1, x2 = map(int, input().split())
        flows.append((x1, x2))

    maxDistance = calculateMaxDistance(n, h, flows)
    print(maxDistance)

main()
