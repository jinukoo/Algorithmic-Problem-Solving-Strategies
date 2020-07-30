# Q: turn black-white picture(quad tree) upside down
# b - if all pixels under are black
# w - if all pixels under are white
# x - if pixels are not one color

# input test cases
n = int(input())
for i in range(n):
    # input number of height and width
    h, w = input().split()
    h = int(h)
    w = int(w)

    # input board
    board = []
    for j in range(h):
        board.append(list(input()))
    
    print(countCovering(board, 0, 0))