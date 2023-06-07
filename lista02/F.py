def findMinTimeToCrossRoad(lights_sequence, current_light):
    curr_light_ptr = -1
    lights_sequence += lights_sequence
    n = len(lights_sequence)
    max_distance = 0
    distance = 0
    
    for i in range(n):
        if lights_sequence[i] == 'g':
            max_distance = max(max_distance, distance)
            curr_light_ptr = -1
            distance = 0
        elif curr_light_ptr != -1:
            distance += 1
        elif lights_sequence[i] == current_light:
            curr_light_ptr = i
            distance += 1

    return max_distance

def main():
    t = int(input())
    
    while t > 0:
        _, current_light = input().split()
        lights_sequence = input()
        answer = findMinTimeToCrossRoad(lights_sequence, current_light)
        print(answer)
        t -= 1
        
main()
