from math import sin, cos, pi

def triangle_fits(largest_side, triangle_side, angle):
    return triangle_side * sin(angle) + triangle_side * cos(angle + pi / 6) <= largest_side

def main():
    A, B = map(int, input().split())
    largest_side = max(A, B)
    smallest_side = min(A, B)
    
    start = 0
    end = pi / 6
    
    while abs(start - end) > 10e-11:
        angle = (start + end) / 2
        triangle_side = smallest_side / cos(angle) # cos(angle) = adj / hip
        
        if triangle_fits(largest_side, triangle_side, angle):
            start = angle
        else:
            end = angle
            
    result = smallest_side / cos(angle)
    print(result)
    
main()
