
def countCovering(b, y, x):
    # advance until meets .
    while y < len(b) and b[y][x] == '#':
        while x < len(b[y]) and b[y][x] == '#':
            x += 1
        if x == len(b[y]):
            y += 1
            x = 0
    print(y, x, b[y][x])
    # base case : reach end successfully
    if y == len(b):
        return 1
    
    total = 0

    # check next block
    # exception reached right end
    if x+1 < len(b[y]) and b[y][x+1] == '.':
        b[y][x] = '#'
        b[y][x+1] = '#'
        # case 1
        """ . .
            .   """
        if y+1 < len(b) and b[y+1][x] == '.':
            b[y+1][x] = '#'
            total += countCovering(b, y, x)
            b[y+1][x] = '.'
        # case 2
        """ . .
              . """
        if y+1 < len(b) and b[y+1][x+1] == '.':
            b[y+1][x+1] = '#'
            total += countCovering(b, y, x)
            b[y+1][x+1] = '.'
        b[y][x] = '.'
        b[y][x+1] = '.'
    
    # next block is unavailable
    if y+1 < len(b) and b[y+1][x] == '.':
        b[y][x] = '#'
        b[y][x+1] = '#'
        # case 3
        """ .
            . . """
        if x+1 < len(b[y+1]) and b[y+1][x+1] == '.':
            b[y+1][x+1] = '#'
            total += countCovering(b, y, x)
            b[y+1][x+1] = '.'

        # case 4
        """   .
            . . """
        if x != 0 and b[y+1][x-1] == '.':
            b[y+1][x-1] = '#'
            total += countCovering(b, y, x)
            b[y+1][x-1] = '.'
    
    return total

    


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
    
    

    