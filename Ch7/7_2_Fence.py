# Q : from fence made out of N woods, find the size of the largest reactange

# Idea : Brute Force
# find all possible reactangles and figure out the max size


# input test cases
c = int(input())
for i in range(c):
    # input number of woods
    n = int(input())
    heights = list(map(int, input().split()))
    
    max = 0
    for j in range(n):
        length = 1
        # find left side length
        satisfied = True
        left = j - 1
        while(satisfied):
            if left >= 0 and heights[left] >= heights[j]:
                length += 1
                left -= 1
            else:
                satisfied = False

        # find right side length
        satisfied = True
        right = j + 1
        while(satisfied):
            if right < n and heights[right] >= heights[j]:
                length += 1
                right += 1
            else:
                satisfied = False
        
        # calculate area
        area = length * heights[j]

        # save the largest area
        if area > max :
            max = area
    
    print(max)