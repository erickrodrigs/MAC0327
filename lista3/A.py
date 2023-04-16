def fastExp(a, e, m):
    if e == 0:
        return 1
    
    x = fastExp(a, e // 2, m)
    x = x * x % m

    if e % 2 == 1:
        x = x * a % m

    return x

def main():
    n = int(input())
    print(fastExp(1378, n, 10))

main()
