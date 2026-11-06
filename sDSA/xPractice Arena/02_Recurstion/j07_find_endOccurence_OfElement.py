def find_first_last(s, target, idx):
    # base case
    if idx < 0:
        return -1, -1

    first, last = find_first_last(s, target, idx - 1)

    if s[idx] == target:
        if first == -1:
            first = idx
        last = idx

    return first, last


string = "solo_onion"
target = 'o'

first, last = find_first_last(string, target, len(string) - 1)

print("String          :", string)
print("Target character:", target)
print("First index     :", first)
print("Last index      :", last)
