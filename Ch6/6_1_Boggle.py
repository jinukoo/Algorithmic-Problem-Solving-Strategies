# Q : from 5*5 alphabet board find the given word from the board

# Idea : By DFS, search all possible ways and check if answer is there


# recursive function
# return boolean wheter found the given word
def hasWord(y, x, word):
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


# find first letter
# return list of locations
def findFirst(ch):
    location = []
    for i in range(5):
        for j in range(5):
            if alphabets[i][j] == ch:
                location.append([i, j])
    return location


# for each test cases
c = int(input())
for _ in range(c):
    # take 5*5 input of alphabets
    alphabets = []
    for ___ in range(5):
        alphabets.append(list(input()))
    # n words to search
    n = int(input())
    for i in range(n):
        existence = False
        word = list(input())
        locations = findFirst(word[0])
        if len(locations) == 0 :
            print("NO")
        for j in range(len(locations)):
            if hasWord(locations[j][0], locations[j][1], word):
                existence = True
                print("YES")
                break
        


        



        
print(hasWord(1,2,"REPEAT"))
