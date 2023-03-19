def can_divide_into_even_weights(w):
    return w >= 4 and w % 2 == 0

w = int(input())
result = can_divide_into_even_weights(w)

print("YES" if result else "NO")
