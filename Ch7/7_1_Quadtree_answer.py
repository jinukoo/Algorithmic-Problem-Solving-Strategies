# Q: turn black-white picture(quad tree) upside down
# b - if all pixels under are black
# w - if all pixels under are white
# x - if pixels are not one color

# book solution in python code
# Idea : use recursion 4 times to take care of 4 childrens when x
# deleted input list instead of using iterator

# returns reversed quadtree list
def reverse(s):
    # base case : subtrees are all one color
    if s[0] != 'x':
        elm = s.pop(0)      # erase the element from the list
        return [ elm ]
    else:
        # x appeared
        s.pop(0)            # delete x from the list
        upper_left = reverse(s)
        upper_right = reverse(s)
        lower_left = reverse(s)
        lower_right = reverse(s)
        return [ 'x' ] + lower_left + lower_right + upper_left + upper_right


# input test cases
n = int(input())
for i in range(n):
    s = list(input())
    res = ""
    res = res.join(reverse(s))
    print(res)