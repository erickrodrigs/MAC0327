from typing import List

def isPossibleToRotate(index: int, n: int, a: List[int], sum_degree: int):
  if index == n:
    return sum_degree % 360 == 0
  else:
    clockwiseRotation = isPossibleToRotate(index + 1, n, a, sum_degree + a[index])
    counterClockwiseRotation = isPossibleToRotate(index + 1, n, a, sum_degree - a[index])
    return clockwiseRotation or counterClockwiseRotation

def main():
  n = int(input())
  a = []

  for _ in range(n):
    ai = int(input())
    a.append(ai)

  if isPossibleToRotate(0, n, a, 0):
    print('YES')
  else:
    print('NO')

main()
