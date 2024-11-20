

for i in range(1, 101):
    k = 1 / i
    p = k
    for j in range(1, 100):
        p = p * 10
    # p = int(p)
    p = str(p)
    # print(p)
    for j in range(1, len(p)):
        if p[0] == p[j]:
            ans = ""
            for k in range(0, j):
                ans += p[k]
            print("i = " + str(i) + " cir is " + ans)
            break


            