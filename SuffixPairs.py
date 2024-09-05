import sys

# returns whether 1 is suffix of 2
def is_suffix(word_1, word_2):
    return word_2[-len(word_1):] == word_1

def main():
    words = []
    n = int(input())
    for i in range(n):
        words.append(str(input()))
    words.sort(key=len)
    numPairs = 0

    total = 0
    hasSuffix = {}
    for i in range(n):
        hasSuffix[i] = [set(), 0]
        hasSuffix[i][0].add(i)
        for j in range(i-1, -1, -1):
            if (j in hasSuffix[i][0]):
                continue
            elif (is_suffix(words[j], words[i])):
                hasSuffix[i][0].update(hasSuffix[j][0])
                hasSuffix[i][1] += hasSuffix[j][1] + 1
        total += hasSuffix[i][1]
    # print(hasSuffix)
    print(total)

if __name__ == "__main__":
    main()
