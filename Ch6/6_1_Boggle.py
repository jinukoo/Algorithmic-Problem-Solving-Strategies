# take 5*5 input
alphabets = []
print("type in 5*5 letters:")
for i in range(5):
    line = input()
    alphabets.append(line.split(' '))

# check input
# print("Your input is:")
# for i in range(5):
#     for j in range(5):
#         print(alphabets[i][j], end=' ')
#     print(" ")


# recursive function
def hasWord(y, x, word):
    # print(f"current place : {y}, {x} need to find {word}")
    # print(f"current letter : {alphabets[y][x]}")
    # current letter corresponds
    if word[0] == alphabets[y][x]:
        # base case : found all word
        if len(word) == 1:
            return True
    
        # change word
        remain_word = word[1:]

        # next place to search
        for i in range(-1, 2):
            for j in range(-1, 2):
                # no need to search current place
                if i == 0 and j == 0:
                    continue
                # next place cannot exceed range(0:5)
                if (y+i) < 0 or (y+i) > 4:
                    continue
                if (x+j) < 0 or (x+j) > 4:
                    continue
                # if word exisits
                if(hasWord(y+i, x+j, remain_word)):
                    return True
        
        return False

    # No match
    else:
        return False
        
print(hasWord(1,2,"REPEAT"))
