# Q: turn black-white picture(quad tree) upside down
# b - if all pixels under are black
# w - if all pixels under are white
# x - if pixels are not one color

# solve the problem without making tree object
# manipulate string

# makes list into a quadtree like list
def make_quadtree(s):
    tree = []
    tree.append(s.pop(0))
    if tree[0] == 'x':
        for _ in range(4):
            tree.append(make_quadtree(s))
    return tree


def reverse(tree):
    # base case : subtrees are all one color
    if len(tree) == 1:
        return
    else:
        # swap index 1 and 3
        temp = tree[1]
        tree[1] = tree[3]
        tree[3] = temp
        # swap index 2 and 4
        temp = tree[2]
        tree[2] = tree[4]
        tree[4] = temp

        for i in range(1, 5):
            reverse(tree[i])


def printTree(tree):
    if len(tree) == 1:
        print(tree[0], end="")
    else:
        print(tree[0], end="")
        for i in range(1,5):
            printTree(tree[i])


# input test cases
n = int(input())
for i in range(n):
    s = list(input())
    quadtree = make_quadtree(s)
    reverse(quadtree)
    printTree(quadtree)
    print()
