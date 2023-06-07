def find_minimum_distance(lanterns, n, l):
    lanterns.sort()
    distance = 0
    max_diff = 0
    
    for i in range(1, n):
        diff = lanterns[i] - lanterns[i - 1]
        if diff > max_diff:
            max_diff = diff
            
    distance = max_diff / 2
    
    # treat corners
    if lanterns[0] > 0 and lanterns[0] - 0 > distance:
        distance = lanterns[0] - 0
    if lanterns[n - 1] < l and (l - lanterns[n - 1]) > distance:
        distance = (l - lanterns[n - 1])
        
    return distance

def main():
    n, l = map(int, input().split())
    lanterns = list(map(int, input().split()))
    distance = find_minimum_distance(lanterns, n, l)
    print(distance)

main()
