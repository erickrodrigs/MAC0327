def isPalindrome(number: int):
  return str(number) == str(number)[::-1]

def getNextPalindromePassword(password: int):
  if isPalindrome(password):
    return password

  previousPalindrome = password - 1
  nextPalindrome = password + 1

  while not isPalindrome(abs(previousPalindrome)):
    previousPalindrome -= 1

  while not isPalindrome(nextPalindrome):
    nextPalindrome += 1

  if len(str(previousPalindrome)) != 6:
    return nextPalindrome
  elif len(str(nextPalindrome)) != 6:
    return previousPalindrome
  elif password - previousPalindrome <= nextPalindrome - password:
    return previousPalindrome
  else:
    return nextPalindrome

def main():
  n = int(input())
  
  while n > 0:
    password = int(input())
    print(getNextPalindromePassword(password))
    n -= 1

main()
