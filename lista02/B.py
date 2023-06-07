def countPairs(socks):
    socks.sort()
    
    sameColorCounter = 1
    total = 0
    
    for i in range(1, len(socks)):
        if socks[i] == socks[i - 1]:
            sameColorCounter += 1
        else:
            total += (sameColorCounter // 2)
            sameColorCounter = 1
    
    if sameColorCounter > 1:
        total += (sameColorCounter // 2)
    
    return total

def main():
    n = int(input())
    socks = list(map(int, input().split()))
    print(countPairs(socks))

main()
