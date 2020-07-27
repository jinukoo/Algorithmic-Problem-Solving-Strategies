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

    print(board)