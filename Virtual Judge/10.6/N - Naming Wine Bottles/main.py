T = int(input())

dic = dict()
id = 0


def getName(x):
    if x == 0:
        return ['a']
    s = []
    while x > 0:
        s.append(chr(x % 26 + 97))
        x //= 26
    return s[::-1]


for i in range(T):
    s = input()
    n = len(s)
    s = s[0:n - 1]
    v = eval(s)
    if v not in dic:
        dic[v] = getName(id)
        id = id + 1
    print(''.join(dic[v]))
