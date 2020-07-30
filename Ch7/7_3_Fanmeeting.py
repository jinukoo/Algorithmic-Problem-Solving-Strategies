# Q : idols' sex and fans' sex are given. 
#     count how many times all memebers of idols hug fans
#     in case of M - M no hug occurs

# Idea : Think hug as a multiplication

# input test cases
c = int(input())
for i in range(c):
    # input idol members
    idols = list(input())
    # convert M -> 1 / F -> 0
    for j in range(len(idols)):
        if idols[j] == 'M':
            idols[j] = 1
        else :
            idols[j] = 0
    
    # input fans
    fans = list(input())
    # convert M -> 1 / F -> 0
    for j in range(len(fans)):
        if fans[j] == 'M':
            fans[j] = 1
        else :
            fans[j] = 0
    
    hugs = 0

    # exception : idols are greater than fans
    if len(idols) > len(fans) :
        print(0)
    else:
        # for each hugging incidents
        for j in range(len(fans) - len(idols) + 1):
            all_hugs = True
            # check if M - M hug occurs
            for k in range(len(idols)):
                if idols[k] * fans[j + k] == 1:
                    all_hugs = False
                    break
            
            # loop ended without M - M hug
            if all_hugs:
                hugs += 1
    
    print(hugs)

