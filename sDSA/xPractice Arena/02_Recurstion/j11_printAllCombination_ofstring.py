def printCombination(str, idx, substr) :
    if len(str) == idx:
        print(f'S[{substr}]')
        return

    printCombination(str, idx+1, substr+str[idx])
    printCombination(str, idx+1, substr)

str = "abc"
printCombination(str, 0, "") # this true and false doesnt affect in the main

