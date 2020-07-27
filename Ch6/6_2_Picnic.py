# python code corresponding to the book algoritm

# recursive function : finds one possibility
# to prevent double counting : find pair in ascending order
def countPairings(taken):
    # find the first number of student unmatched
    firstFree = -1
    for i in range(len(taken)):
        if not taken[i]:
            firstFree = i
            break

    # base case(all students are matched)
    if firstFree == -1:
        return 1

    # find student to match
    ret = 0
    for pairWith in range(firstFree + 1, len(taken)):
        if not taken[pairWith] and areFriends[firstFree][pairWith]:
            taken[firstFree] = True
            taken[pairWith] = True
            ret += countPairings(taken)
            taken[firstFree] = False
            taken[pairWith] = False
    return ret


# input test cases
n = int(input())
for i in range(n):
    # input number of friends and pairs
    n_friends, n_pairs = input().split()
    n_friends = int(n_friends)
    n_pairs = int(n_pairs)

    # input pairs
    input_list = input().split()
    pair_list = []
    for x in input_list:
        pair_list.append(int(x))

    # two dimensional array for indicating friends
    areFriends = [ [False] * n_friends for j in range(n_friends) ]

    for j in range(n_pairs):
        areFriends[pair_list[2 * j]][pair_list[2 * j + 1]] = True
        areFriends[pair_list[2 * j + 1]][pair_list[2 * j]] = True
    
    # true if found pair
    taken = [False] * n_friends

    print(countPairings(taken))
