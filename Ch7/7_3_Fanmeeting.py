# Q : idols' sex and fans' sex are given. 
#     count how many times all memebers of idols hug fans
#     in case of M - M no hug occurs

# Idea : Think hug as a multiplication of two big numbers

# represent big number as a list(index 0 : LSB)
# No carry out needed!

# a += b * (10^k)
def addTo(a, b, k):
    # b *= (10^k)
    for _ in range(k):
        b.insert(0, 0)
    
    # make a the bigger number
    if len(a) < len(b):
        temp = a
        a = b
        b = temp
    
    # a += b
    for i in range(len(b)):
        a[i] += b[i]

    

# a -= b (assume a >= b)
def subFrom(a, b):
    if len(a) < len(b): 
        return subFrom(b, a)
    for i in range(len(b)):
        a[i] -= b[i]
        

# karatsuba algorithm of multiplying two big numbers
# without carrying(?)
def karatsuba(a, b):
    an = len(a)
    bn = len(b)
    if an < bn:
        return karatsuba(b, a)
    
    if an == 0 or bn == 0:
        return []

    half = an // 2
    a0 = a[0:half]
    a1 = a[half:an]
    b0 = b[0:min(bn, half)]
    b1 = b[min(bn, half):bn]

    # z2 = a1 * b1
    z2 = karatsuba(a1, b1)
    # z0 = a0 * b0
    z0 = karatsuba(a0, b0)

    # z1 = (a0 + a1) * (b0 + b2) - z0 - z2
    addTo(a0, a1, 0)
    addTo(b0, b1, 0)
    z1 = karatsuba(a0, b0)
    subFrom(z1, z0)
    subFrom(z1, z2)

    # res = z0 + z1 * 10^half + z2 * 10^(half*2)
    res = []
    addTo(res, z0, 0)
    addTo(res, z1, half)
    addTo(res, z2, half * 2)
    return res


# input test cases
c = int(input())
for i in range(c):
    # input idol members
    idols = list(input())
    n_idols = len(idols)
    # convert M -> 1 / F -> 0
    for j in range(n_idols):
        if idols[j] == 'M':
            idols[j] = 1
        else :
            idols[j] = 0
    
    # input fans
    fans = list(input())
    n_fans = len(fans)
    fans_rev = []
    # convert M -> 1 / F -> 0 & reverse
    for j in range(n_fans):
        if fans[n_fans - j - 1] == 'M':
            fans_rev.append(1)
        else :
            fans_rev.append(0)
    
    hugs = 0

    # exception : idols are greater than fans
    if n_idols > n_fans :
        print(0)
    else:
        res = karatsuba(idols, fans_rev)
        for j in range(n_idols - 1, n_fans):
            if res[j] == 0:
                hugs += 1
    
    print(hugs)


# 1. Multiplication of two big numbers!
# 2. Did not fully understand karatsuba algorithm