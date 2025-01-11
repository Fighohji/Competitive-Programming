T = int(input())
while T > 0:
    T -= 1

    a, b, c, x, y, d = map(int, input().split())

    '''
    A
    '''
    tmp = d // x * a
    Ans = tmp

    # zhi yong A
    res = d % x
    if res > 0:
        Ans += a

    # bu huan che 
    if d >= x:
        if y >= res:
            Ans = min(Ans, tmp + res * b)
        else:
            Ans = min(Ans, tmp + y * b + (res - y) * c)

        # jin liang yong B
        cnt = d // x
        if res <= cnt * y:
            Ans = min(Ans, tmp + res * b)
        else:
            Ans = min(Ans, tmp + cnt * y * b + (res - cnt * y) * c)

    '''
    B
    '''
    tmp = d // (x + y) * (a + b * y)

    res = d % (x + y)
    if d >= x + y:
        Ans = min(Ans, tmp + res * c)

    if res <= x:
        Ans = min(Ans, tmp + a)
        tot = d // (x + y) * y
        if x - res <= tot:
            Ans = min(Ans, tmp + a - b * (x - res))
    else:
        Ans = min(Ans, tmp + a + (res - x) * b)

    '''
    C
    '''
    if d <= x:
        Ans = min(Ans, a)
    elif d <= x + y:
        Ans = min(Ans, a + (d - x) * b)
    else:
        Ans = min(Ans, a + y * b + (d - x - y) * c)
    print(Ans)


