def is_palindrome(frequencies):
    has_odd = False
    for value in frequencies.values():
        if value % 2 != 0:
            if has_odd:
                return False
            
            has_odd = True
    
    return True

def main():
    frequencies = { char: 0 for char in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" }
    s = input()
    
    for char in s:
        frequencies[char] += 1
    
    if not is_palindrome(frequencies):
        print("NO SOLUTION")
        return
    
    prefix = ""
    middle = ""
    suffix = ""
    
    for letter, frequency in frequencies.items():
        if frequency % 2 == 0:
            prefix += letter * (frequency // 2)
            suffix += letter * (frequency // 2)
        else:
            middle += letter * frequency
            
    result = prefix + middle + suffix[::-1]
    print(result)
    
main()
