# Q : from fence made out of N woods, find the size of the largest reactange

# Idea : Divide and Conquer
# divide the fence in half
# the largest should be either in the left, in the right, or sideded in the middle


def solve(left, right):
    # base case : left == right
    if left == right :
        return heights[left]
    
    half = (left + right) // 2

    # check largest in the left and right
    res = max(solve(left, half), solve(half + 1, right))

    # check largest in the middle
    low = half
    high = half + 1
    
    # check smallest middle position rectangle (size 2)
    height = min(heights[low], heights[high])
    res = max(res, height * 2)

    # iterate until cannot expand to left and right
    while left < low or high < right :
        # expand to more larger height
        # expand to right
        if high < right and (low == left or heights[low - 1] < heights[high + 1]):
            high += 1
            height = min(height, heights[high])
        # expand to left
        else :
            low -= 1
            height = min(height, heights[low])
        
        # compare area
        res = max(res, height * (high - low + 1))

    return res


# input test cases
c = int(input())
for i in range(c):
    # input number of woods
    n = int(input())
    heights = list(map(int, input().split()))
    print(solve(0, n - 1))

# O(n) = nlogn algorithm