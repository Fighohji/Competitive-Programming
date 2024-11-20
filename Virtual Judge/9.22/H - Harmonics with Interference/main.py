s = input()
t = input()
n, m = len(s), len(t)

pos = []
for i in range(n):
    if s[i] == '*':
        pos.append(n - i - 1)

for i in range(m):
    if t[i] == '*':
        pos.append(m - i - 1 + n)

k = len(pos)
x, y = 0, 0
for i in range(n):
    if s[i] == '1':
        x += (1 << (n - i - 1))
for i in range(m):
    if t[i] == '1':
        y += (1 << (m - i - 1))
for i in range(1 << k):
    nx, ny = 0, 0
    for j in range(k):
        if (i >> j & 1) == 0:
            continue
        if pos[j] < n:
            nx += (1 << pos[j])
        else:
            ny += (1 << (pos[j] - n))

    if (x + nx) % (y + ny) == 0:
        Ans = []
        for i in range(n):
            Ans.append((x + nx) >> i & 1)
        # print(Ans)
        print(''.join(map(str, Ans[::-1])))
        exit(0)
