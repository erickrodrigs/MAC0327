def sum(a, b):
    return (a + b)

n = int(input())

while n > 0:
    a, b = input().split()
    print(sum(int(a), int(b)))
    n -= 1
