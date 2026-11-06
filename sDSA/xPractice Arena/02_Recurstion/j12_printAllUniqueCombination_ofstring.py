def printCombination(s, idx, substr, seen):
    if idx == len(s):
        if substr not in seen:
            print(f'S[{substr}]')
            seen.add(substr)
        return

    # include current character
    printCombination(s, idx + 1, substr + s[idx], seen)

    # exclude current character
    printCombination(s, idx + 1, substr, seen)


s = "aaa"
seen = set() #hash set
printCombination(s, 0, "", seen)
