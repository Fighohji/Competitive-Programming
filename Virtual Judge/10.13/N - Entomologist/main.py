n = int(input())

s = input().split()

L = 0
R = 2147483647
for i in range(1, n):
    if s[i] != '?':
        num = int(s[i])
        L = max(L, num * (i + 1) - (i + 1) // 2)
        R = min(R, L + i)

print(L)
