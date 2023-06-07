def generate_dict_key(characters_freq):
    return ",".join(map(str, characters_freq))

def get_number_of_happy_substr(s):
    answer = 0
    frequencies = dict()
    characters_freq = [0] * 10
    key = generate_dict_key(characters_freq)
    frequencies[key] = 1

    for character in s:
        index = ord(character) - ord('0')
        characters_freq[index] += 1
        characters_freq[index] %= 2
        key = generate_dict_key(characters_freq)

        if key in frequencies:
            frequencies[key] += 1
        else:
            frequencies[key] = 1

    for value in frequencies.values():
        answer += (value * (value - 1)) // 2

    return answer

def main():
    s = input()
    answer = get_number_of_happy_substr(s)
    print(answer)

main()
