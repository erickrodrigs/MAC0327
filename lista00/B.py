t = int(input())

while t > 0:
    length = int(input())
    word = input()
    
    max_letter = 'a'
    
    for letter in word:
        if letter > max_letter:
            max_letter = letter
    
    result = ord(max_letter) - ord('a') + 1
    print(result)
    t -= 1
